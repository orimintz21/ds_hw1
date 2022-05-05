#ifndef AVL_TREE_H_
#define AVL_TREE_H_

#include "TreeNode.h"
#include "memory"
#include "AvlTreeExceptions.h"
#include <cmath>
#include <iostream>

using std::cout;
using std::endl;
using std::shared_ptr;
//Pred(A,B) = true -> A>B
template<class T, class Pred>
class AvlTree
{
public:
    int size;
    Pred comp;
    shared_ptr<TreeNode<T>> root;

    AvlTree(Pred comp, T n_root);
    AvlTree(Pred comp);
    virtual ~AvlTree() = default;

    bool equal(T a, T b) const;
    int getSize() const;

    const shared_ptr<TreeNode<T>> &getRoot() const;

    //LL rotation
    void LL(shared_ptr<TreeNode<T>> rotation_root);
    //LR rotation
    void LR(shared_ptr<TreeNode<T>> rotation_root);
    //RL rotation
    void RL(shared_ptr<TreeNode<T>> rotation_root);
    //RR rotation
    void RR(shared_ptr<TreeNode<T>> rotation_root);
    //find if the element is in the tree, if not throws not_in_tree
    std::shared_ptr<TreeNode<T>> find(T element);
    //inserts the element if the elements is not already in the tree, if it is, throws already_in_tree
    std::shared_ptr<TreeNode<T>> insert(T element);

    void fixBalace(std::shared_ptr<TreeNode<T>> form);

    void remove(T element);

    void removeLeaf(shared_ptr<TreeNode<T>> to_remove, TreeNode<T>* p, bool is_right);

    void removeOneSon(shared_ptr<TreeNode<T>> to_remove, TreeNode<T>* p,  bool is_right);

    void removeTwoSons(shared_ptr<TreeNode<T>> to_remove, TreeNode<T>* p,  bool is_right);

    void printTree(int space);
};

template<class T>
void printTreeAux(shared_ptr<TreeNode<T>> a, int space)
{
    if (a == nullptr)
        return;

    space += 5;
    printTreeAux<T>(a->right, space);
    cout<<endl;
    for (int i = 5; i < space; i++)
        cout<<" ";
    cout<<a->data<<"\n";
    printTreeAux<T>(a->left, space);

}



template<class T, class Pred>
void AvlTree<T,Pred>::printTree(int space) {
    printTreeAux<T>(root, space);
}



template<class T>
shared_ptr<TreeNode<T>> emptyAux(int h);



template<class T, class Pred, class RangePred>
void countInRange(T min_e, T max_e, RangePred rCond, int* all_elements, int* passed_elements, AvlTree<T,Pred> tree)
{
    *all_elements =0;
    *passed_elements =0;
    std::shared_ptr<TreeNode<T>> it = tree.root;
    while(it!= nullptr && tree.comp(min_e,it->data) && !tree.equal(min_e,it->data))
    {
        it = it->right;
    }
    while (it!= nullptr && tree.comp(it->data,min_e) && !tree.equal(min_e, it->data))
    {
        it = it->left;
    }
    countInRangeAux(it ,min_e ,max_e, rCond, all_elements, passed_elements,tree);

}

template<class T, class Pred, class RangePred>
void countInRangeAux(shared_ptr<TreeNode<T>> loc,T min_e,T max_e, RangePred rCond, int* all_elements, int* passed_elements, AvlTree<T,Pred> tree)
{
    if(loc == nullptr)
        return;

    if(tree.comp(loc->data, max_e))
        return;

    //only happens in the firs iteration
    if(tree.comp(min_e), loc->data)
        return;
    countInRangeAux(loc->left, max_e, rCond, all_elements, passed_elements, tree);
    (*all_elements)++;
    if(rCond(loc->data))
    {
        (*passed_elements)++;
    }
    countInRangeAux(loc->right,max_e,rCond,all_elements,passed_elements,tree);
}


template<class T, class Pred>
AvlTree<T, Pred>::AvlTree(Pred comp, T n_root):size(1), comp(comp), root(nullptr) {
    shared_ptr<TreeNode<T>> ptr_n_root =shared_ptr<TreeNode<T>>(new TreeNode<T>(n_root));
    root = ptr_n_root;
}

template<class T, class Pred>
AvlTree<T, Pred>::AvlTree(Pred comp): size(0),comp(comp) ,root(nullptr) {}

template<class T, class Pred>
int AvlTree<T, Pred>::getSize() const {
    return size;
}

template<class T, class Pred>
const shared_ptr<TreeNode<T>> &AvlTree<T, Pred>::getRoot() const
{
    return root;
}

template<class T, class Pred>
bool AvlTree<T, Pred>::equal(T a, T b) const
{
    if(!comp(a,b) && !comp(b,a))
        return true;
    return false;
}


template<class T, class Pred>
void AvlTree<T,Pred>::LL(shared_ptr<TreeNode<T>> rotation_root)
{
    std::shared_ptr<TreeNode<T>> switch_with = rotation_root->left;
    //set rotation_root parent
    if(rotation_root->parent != nullptr) {
        bool left_son = false;
        if (rotation_root->parent->left == rotation_root) {
            left_son = true;
        }
        if (left_son) {
            rotation_root->parent->left = switch_with;
        } else {
            rotation_root->parent->right = switch_with;
        }
    }


    if(rotation_root == root)
    {
        root = switch_with;
    }
    rotation_root->left = switch_with->right;
    switch_with->right = rotation_root;
    switch_with->parent = rotation_root->parent;
    rotation_root->parent = &(*switch_with);
    rotation_root->calcHeight();
    switch_with->calcHeight();
}

template<class T, class Pred>
void AvlTree<T,Pred>::LR(shared_ptr<TreeNode<T>> rotation_root)
{
    std::shared_ptr<TreeNode<T>> first_layer = rotation_root->left;
    std::shared_ptr<TreeNode<T>> second_layer = first_layer->right;
    TreeNode<T>* parent = rotation_root->parent;
    if(parent!= nullptr)
    {
        bool left_son = false;
        if (rotation_root->parent->left == rotation_root) {
            left_son = true;
        }
        if(left_son){
            parent->left = second_layer;
        }
        else{
            parent->right = second_layer;
        }
    }
    if(rotation_root == root)
    {
        root = second_layer;
    }
    rotation_root->left = second_layer->right;
    first_layer->right = second_layer->left;
    second_layer->left = first_layer;
    second_layer->right = rotation_root;
    second_layer->parent = rotation_root->parent;
    rotation_root->parent = &(*second_layer);
    first_layer->parent = &(*second_layer);
    rotation_root->calcHeight();
    rotation_root->clacBalance();
    first_layer->clacBalance();
    second_layer->clacBalance();
}

template<class T, class Pred>
void AvlTree<T,Pred>::RL(shared_ptr<TreeNode<T>> rotation_root)
{
    std::shared_ptr<TreeNode<T>> first_layer = rotation_root->right;
    std::shared_ptr<TreeNode<T>> second_layer = first_layer->left;
    TreeNode<T>* parent = rotation_root->parent;
    if(parent!= nullptr)
    {
        bool left_son = false;
        if (rotation_root->parent->left == rotation_root) {
            left_son = true;
        }
        if(left_son){
            parent->left = second_layer;
        }
        else{
            parent->right = second_layer;
        }
    }
    if(rotation_root == root)
    {
        root = second_layer;
    }
    rotation_root->right = second_layer->left;
    first_layer->left = second_layer->right;
    second_layer->right = first_layer;
    second_layer->left = rotation_root;
    second_layer->parent = rotation_root->parent;
    rotation_root->parent = &(*second_layer);
    first_layer->parent = &(*second_layer);
    rotation_root->calcHeight();
    rotation_root->clacBalance();
    first_layer->clacBalance();
    second_layer->clacBalance();

}

template<class T, class Pred>
void AvlTree<T,Pred>::RR(shared_ptr<TreeNode<T>> rotation_root)
{
    std::shared_ptr<TreeNode<T>> switch_with = rotation_root->right;
    //set rotation_root parent
    if(rotation_root->parent != nullptr) {
        bool left_son = false;
        if (rotation_root->parent->left == rotation_root) {
            left_son = true;
        }
        if (left_son) {
            rotation_root->parent->left = switch_with;
        } else {
            rotation_root->parent->right = switch_with;
        }
    }
    if(rotation_root == root)
    {
        root = switch_with;
    }
    rotation_root->right = switch_with->left;
    switch_with->left = rotation_root;
    switch_with->parent = rotation_root->parent;
    rotation_root->parent = &(*switch_with);
    rotation_root->calcHeight();
    switch_with->calcHeight();
    rotation_root->clacBalance();
    switch_with->clacBalance();
}

template<class T, class Pred>
std::shared_ptr<TreeNode<T>> AvlTree<T,Pred>::find(T element)
{
    std::shared_ptr<TreeNode<T>> temp = root;
    while(true)
    {
        if(temp == nullptr)
        {
            throw not_in_tree();
        }
        //temp>element
        if(comp(temp->data, element))
        {
            temp = temp->right;
        }
        //temp<element
        else if(comp(element, temp->data))
        {
            temp = temp->left;
        }
        else {
            return temp;
        }
    }
}


template<class T, class Pred>
shared_ptr<TreeNode<T>> AvlTree<T,Pred>::insert(T element) {
    std::shared_ptr<TreeNode<T>> temp = root;
    std::shared_ptr<TreeNode<T>> last = root;
    std::shared_ptr<TreeNode<T>> n_element = std::shared_ptr<TreeNode<T>>(new TreeNode<T>(element));

    if(temp == nullptr)
    {
        root = n_element;
    }
    else{
        bool is_right = false;
        while(temp != nullptr)
        {
            //temp>element
            if(comp((temp->data), n_element->data))
            {
                last = temp;
                is_right = true;
                temp = temp->right;
            }
            //temp<element
            else if(comp(n_element->data, temp->data))
            {
                last = temp;
                is_right = false;
                temp = temp->left;
            }
            else {
                throw already_in_tree();
            }
        }
        if(is_right)
        {
            last->right = n_element;
            n_element->parent = &(*last);
        } else
        {
            last->left = n_element;
            n_element->parent = &(*last);
        }
    }
    size++;
    fixBalace(n_element);
    return n_element;
}

template<class T, class Pred>
void AvlTree<T,Pred>::fixBalace(std::shared_ptr<TreeNode<T>> form){
    std::shared_ptr<TreeNode<T>> temp = form;
    while (temp!= nullptr)
    {
        temp->calcHeight();
        if(temp->clacBalance() == 2)
        {
            if(temp->left->clacBalance() >= 0)
            {
                LL(temp);
            }
            else{
                LR(temp);
            }
        } else if(temp->clacBalance() == -2)
        {
            if(temp->right->clacBalance() >= 0)
            {
                RR(temp);
            } else {
                RL(temp);
            }
        }
        temp = std::shared_ptr<TreeNode<T>>(temp->parent);
    }
}

template<class T, class Pred>
void AvlTree<T,Pred>::remove(T element)
{
    shared_ptr<TreeNode<T>> to_remove = this->find(element);
    TreeNode<T>* r_parent = to_remove->parent;
    
    bool is_right = false;
    if (r_parent != nullptr)
    {
        if(r_parent->right == to_remove)
        {
            is_right = true;
        }
    }

    //to_remove is a leaf
    if(to_remove->isLeaf())
    {
        removeLeaf(to_remove, r_parent, is_right);
    }

    //to_remove has one son (which son?)
    else if(to_remove->left == nullptr || to_remove->right ==nullptr)
    {
        removeOneSon(to_remove, r_parent, is_right);
    }

    //to_remove has two sons
    else
    {
        removeTwoSons(to_remove, r_parent, is_right);
        return;
    }

}

template<class T, class Pred>
void AvlTree<T, Pred>::removeLeaf(shared_ptr<TreeNode<T>> to_remove, TreeNode<T>* p , bool is_right)
{
    if(p==nullptr)
    {
        root = nullptr;
    }
    else if(is_right)
    {
        p->right = nullptr;
    }
    else
    {
        p->left = nullptr;
    }
    size--;
    fixBalace(std::shared_ptr<TreeNode<T>>(p));
}

template<class T, class Pred>
void AvlTree<T, Pred>::removeOneSon(shared_ptr<TreeNode<T>> to_remove, TreeNode<T>* p ,bool is_right)
{
    if(to_remove->left == nullptr)
    {
        if(p==nullptr)
        {
            root = to_remove->right;
        }
        else if(is_right)
        {
            p->right = to_remove->right;

        }
        else
        {
            p->left = to_remove->right;
        }
        to_remove->right->parent = p;

    }

    if(to_remove->right == nullptr)
    {
        if(p == nullptr)
        {
            root = to_remove->left;
        }
        else if(is_right)
        {
            p->right = to_remove->left;
        }
        else
        {
            p->left = to_remove->left;
        }
        to_remove->left->parent = p;
    }
    size--;
    fixBalace(std::shared_ptr<TreeNode<T>>(p));
    
}


template<class T, class Pred>
void AvlTree<T, Pred>::removeTwoSons(shared_ptr<TreeNode<T>> to_remove, TreeNode<T>* p, bool is_right)
{
    bool is_son = true;
    shared_ptr<TreeNode<T>> to_switch = to_remove->right;
    while (to_switch->left != nullptr)
    {   
        is_son = false;
        to_switch = to_switch->left;
    }

    TreeNode<T>* parent_w = to_switch->parent;
    shared_ptr<TreeNode<T>> son_w =  to_switch->right;

    if (p == nullptr) {
        to_switch->parent = nullptr;
        root = to_switch;
    }
    else if(is_right)
    {
        to_switch->parent = p ;   
        p->right = to_switch;
    }
    else
    {
        to_switch->parent = p;   
        p->left = to_switch;
    }

    to_switch->left = to_remove->left;

    if (is_son) 
    {
        to_switch->right = to_remove;
        parent_w = &(*to_switch);
    }
    else
    {
        to_switch->right = to_remove->right;
    }
    to_switch->left = to_remove->left;
    to_remove->parent = parent_w;
    to_remove->left->parent = &(*to_switch);
    to_remove->right->parent = &(*to_switch);
    to_remove->left = nullptr;
    to_remove->right = son_w;
    
    //to_remove is a leaf or an element with one son
    //it's the left son
    if(to_remove->isLeaf())
    {
        removeLeaf(to_remove, to_remove->parent, false);
    }
    else
    {
        removeOneSon(to_remove, to_remove->parent, false);
    }
}

//to check if problems
template<class T>
void TreeNodeToArrInOrder(T* arr, int& ind, shared_ptr<TreeNode<T>> node)
{
    if(node == nullptr)
        return;
    TreeNodeToArrInOrder(arr, ind, node->left);
    arr[ind] = node->data;
    ind++;
    TreeNodeToArrInOrder(arr,ind,node->right);
}
//?
template<class T, class Pred>
T* AvlTreeToArrInOrder(AvlTree<T,Pred> tree)
{  
    T* arr = new T[tree.size];
    int i=0;
    TreeNodeToArrInOrder<T>(arr, i , tree.root);
    return arr;   
}

template<class T, class Pred>
T* mergeArray(T arr1[], int size1 ,T arr2[], int size2 ,Pred cond)
{
    int i1 = 0 ;
    int i2 = 0 ;
    int n_i = 0;

    T* n_arr = new T[size1+size2];
    while(i1<size1 && i2<size2)
    {
        if(cond(arr2[i2],arr1[i1]))
        {
            n_arr[n_i] = arr2[i2];
            n_i++;
            i2++;
        }
        else{
            n_arr[n_i] = arr1[i1];
            n_i++;
            i1++;
        }
    }
    while (i1<size1)
    {
        n_arr[n_i] = arr1[i1];
        n_i++;
        i1++;
    }
    while (i2<size2)
    {
        n_arr[n_i] = arr2[i2];
        n_i++;
        i2++;
    }

    return n_arr;
}
template<class T, class Pred>
void revInOrderDelete(shared_ptr<TreeNode<T>> p, int* diff);

template<class T>
void inorderFill(shared_ptr<TreeNode<T>> p, T* arr, int *ind);

template<class T, class Pred>
shared_ptr<TreeNode<T>> creatingMergedTree(int size, T* merged_arr)
{
    int h = ceil(log2(size)); 
    int n_size =pow(2,h)-1; 
    int diff = n_size-size;
    std::shared_ptr<TreeNode<T>> full_tree = emptyAux<T>(h);
    int ind = 0;
    if (diff > 0)
    {
        revInOrderDelete<T,Pred>(full_tree, &diff);
    }
    inorderFill<T>(full_tree,  merged_arr, &ind);
    return full_tree;

}
template<class T, class Pred>
void revInOrderDelete(shared_ptr<TreeNode<T>> p, int* diff) {
    if (p == NULL || *diff == 0)
        return;
    revInOrderDelete<T,Pred>(p->right, diff);
    bool is_right = false;

    if (p->isLeaf())
    {
    if (p->parent->right == p)
    {
        is_right = true;
    }

        if(is_right)
            p->parent->right = nullptr;
        else
            p->parent->left = nullptr;

        (*diff)--;
    }
    revInOrderDelete<T,Pred>(p->left, diff);
}


template<class T>
void inorderFill(shared_ptr<TreeNode<T>> p, T* arr, int *ind) {
    if (p == NULL) return;
    
    inorderFill<T>(p->left, arr, ind);
    p->data = arr[*ind];
    (*ind)++;
    inorderFill<T>(p->right, arr, ind);
}

template<class T>
shared_ptr<TreeNode<T>> emptyAux(int h){
    if(h==0){
        return nullptr;
    }
    std::shared_ptr<TreeNode<T>> root(new TreeNode<T>());
    root->height = h-1;
    root->left = emptyAux<T>(h-1);
    root->right = emptyAux<T>(h-1);
    if(!root->isLeaf())
    {
        root->left->parent = &(*root);
        root->right->parent = &(*root);
    }

    return root;
}

template<class T, class Pred>
shared_ptr<AvlTree<T,Pred>> margeTrees(AvlTree<T,Pred> a , AvlTree<T,Pred> b)
{   

    T* arr_a =  (AvlTreeToArrInOrder<T,Pred>(a));
    T* arr_b = nullptr;
    try{
        arr_b = AvlTreeToArrInOrder<T,Pred>(b);
    }
    catch (std::bad_alloc&) {
        delete[] arr_a;
        throw std::bad_alloc();
    }
    T* arr_ab = mergeArray<T,Pred>(arr_a, a.size, arr_b ,b.size,a.comp);
    std::shared_ptr<TreeNode<T>> mergedTreeNodes(creatingMergedTree<T,Pred>(a.size + b.size,arr_ab));
    std::shared_ptr<AvlTree<T,Pred>> mergedTree(new AvlTree<T,Pred>(Pred()));
    mergedTree->root = mergedTreeNodes;
    mergedTree->size = a.size+b.size;
    delete[] arr_a;
    delete[] arr_b;
    delete[] arr_ab;
    return  mergedTree;
}

#endif //AVL_TREE_H_