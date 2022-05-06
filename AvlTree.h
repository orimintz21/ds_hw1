//
// Created by lenovo on 26/04/2022.
//

#ifndef HW1_AVLTREE2_H
#define HW1_AVLTREE2_H
#include "Node.h"
#include "AvlTreeExceptions.h"
#include <iostream>
#include <cmath>


using std::cout;
using std::endl;

template<class T, class Pred>
class AvlTree
{
public:
    //fields

    //a>b -> a_bigger_b(a,b) = true
    Pred a_bigger_b;
    Node<T>* root;
    Node<T>* max_n;
    Node<T>* min_n;
    int size;

    AvlTree() : root(nullptr), max_n(nullptr), min_n(nullptr), size(0) {
        a_bigger_b = Pred();
    }

    virtual ~AvlTree() {

        if(root!=nullptr){
            delete root;
        }
    }

    bool equal(const T& a,const T& b) const
    {
        return (! a_bigger_b(a,b) && ! a_bigger_b(b,a));
    }

    //main functions
    Node<T>* find(const T& element);
    void insert(const T& element);
    void remove(const T& element);


    //internal functions

    //LL rotation
    void LL(Node<T>* rotation_root);
    //LR rotation
    void LR(Node<T>* rotation_root);
    //RL rotation
    void RL(Node<T>* rotation_root);
    //RR rotation
    void RR(Node<T>* rotation_root);
    void fixBalance(Node<T>* from);


    //for tests
    void printTree(int space) const;

    void removeLeaf(Node<T>* to_remove, Node<T>* p, bool is_right);
    void removeOneSonLeft(Node<T>* to_remove, Node<T>* p , bool is_right);
    void removeOneSonRight(Node<T>* to_remove, Node<T>* p , bool is_right);
    void removeTwoSons(Node<T>* to_remove, Node<T>* p, bool is_right);

    void merge(AvlTree<T,Pred>& source);
    void setMin()
    {
        Node<T>* m = root;
        while(m->left != nullptr)
            m = m->left;
        min_n = m;
    }
    void setMax()
    {
        Node<T>* m = root;
        while(m->right != nullptr)
            m = m->right;
        max_n = m;
    }

};

template<class T>
void AvlTreeToArr(Node<T>* root, Node<T>* arr[], int* loc);

template<class T, class Pred>
void margeNodeArr(Node<T>* a_arr[], int a_size, Node<T>* b_arr[], int b_size, 
                                                Node<T>* ab_arr[], Pred cond);

template<class T>
Node<T>* fromArrToNodes(Node<T>*& root, Node<T>* ab_arr[], int start, int end);

template<class T, class Pred>
void margeTrees(AvlTree<T,Pred>& a, AvlTree<T,Pred>& b, AvlTree<T,Pred>& ab);

template<class T, class Pred>
Node<T>* AvlTree<T, Pred>::find(const T& element)
{
    Node<T>* temp = root;
    while(true)
    {
        if(temp == nullptr)
        {
            throw not_in_tree();
        }
        //temp>element
        if( a_bigger_b(*(temp->data), element))
        {
            temp = temp->left;
        }
            //temp<element
        else if( a_bigger_b(element, *(temp->data)))
        {
            temp = temp->right;
        }
        else {
            return temp;
        }
    }
}


template<class T, class Pred>
void AvlTree<T, Pred>::insert(const T& element)
{
    Node<T>* temp = root;
    Node<T>* last = root;
    if(temp == nullptr)
    {
        Node<T>* n_element = new Node<T>(element);
        root = n_element;
        min_n = n_element;
        max_n = n_element;
        size++;
        return;
    }
    bool is_right = false;
    while(temp != nullptr)
    {
        //temp>element
        if( a_bigger_b(*(temp->data), element))
        {
            last = temp;
            is_right = false;
            temp = temp->left;
        }
        else if(a_bigger_b(element,*(temp->data)))
        {
            last = temp;
            is_right = true;
            temp = temp->right;
        }
        else{
            throw already_in_tree();
        }
    }
    Node<T>* n_node = new Node<T>(element);
    n_node->parent = last;

    if(is_right)
        last->right = n_node;
    else
        last->left = n_node;
    size++;

    if(max_n == nullptr)
        max_n = n_node;
    else if( a_bigger_b(element ,*(max_n->data)))
        max_n = n_node;

    if(min_n == nullptr)
        min_n = n_node;
    else if( a_bigger_b(*(min_n->data), element))
        min_n = n_node;
    calcNodeHeight(n_node);
    fixBalance(n_node);
}



template<class T, class Pred>
void AvlTree<T,Pred>::remove(const T& element)
{
    Node<T>* to_remove = find(element);
    Node<T>* r_parent = to_remove->parent;

    bool is_right = false;
    if (r_parent != nullptr)
    {
        if(r_parent->right == to_remove)
        {
            is_right = true;
        }
    }

    //to_remove is a leaf
    if(to_remove->isALeaf())
    {
        removeLeaf(to_remove, r_parent, is_right);
    }

    //to_remove have only the right son
    else if(to_remove->left == nullptr)
    {
        removeOneSonRight(to_remove, r_parent, is_right);
    }

    else if(to_remove->right == nullptr)
    {
        removeOneSonLeft(to_remove,r_parent,is_right);
    }

    //to_remove have two sons
    else
    {
        removeTwoSons(to_remove, r_parent, is_right);
        return;
    }
}

template<class T, class Pred>
void AvlTree<T,Pred>::removeLeaf(Node<T> *to_remove, Node<T> *p, bool is_right) {

    //the only one node in the tree
    if(p == nullptr)
    {
        root = nullptr;
        max_n = nullptr;
        min_n = nullptr;
    }
    else if(is_right)
    {
        p->right = nullptr;
        //to_remove > p -> to_remove != min_n
        if(to_remove == max_n)
            max_n = p;
    }
    //to_remove is the left son of p
    else{
        p->left = nullptr;
        //to_remove < p -> to_remove != max_n
        if(to_remove == min_n)
            min_n = p;
    }

    size--;
    deleteOnlyThisNodePtr(to_remove);
    fixBalance(p);
}

//to_remove->right == nullptr && to_remove->left != nullptr
template<class T, class Pred>
void AvlTree<T,Pred>::removeOneSonLeft(Node<T> *to_remove, Node<T> *p, bool is_right) {
    if(p == nullptr)
    {
        root = to_remove->left;
        if(max_n == to_remove)
            max_n = to_remove->left;
        //to_remove > to_remove->left --> min_n != to_remove
    }
    else if(is_right)
    {
        p->right = to_remove->left;
        if(max_n == to_remove)
            max_n = to_remove->left;
        //to_remove > to_remove->left --> min_n != to_remove
    }
    else
    {
        p->left = to_remove->left;
        //p>to_remove>to_remove->left --> min_n!= to_remove != max_n
    }
    to_remove->left->parent = p;
    size--;
    deleteOnlyThisNodePtr(to_remove);
    fixBalance(p);
}

//to_remove->left == nullptr && to_remove->right != nullptr
template<class T, class Pred>
void AvlTree<T,Pred>::removeOneSonRight(Node<T> *to_remove, Node<T> *p, bool is_right) {
    if(p == nullptr)
    {
        root = to_remove->right;
        if(min_n == to_remove)
            min_n = to_remove->right;
        //to_remove < to_remove->right --> max_n != to_remove
    }
    else if(is_right)
    {
        p->right = to_remove->right;
        //p<to_remove < to_remove->right --> min_n != to_remove != max_n
    }
    else
    {
        p->left = to_remove->right;
        if(min_n == to_remove)
            min_n = to_remove->right;
        //to_remove < to_remove->right < p --> min_n!= to_remove != max_n
    }
    to_remove->right->parent = p;

    size--;
    deleteOnlyThisNodePtr(to_remove);
    fixBalance(p);
}

template<class T, class Pred>
void AvlTree<T,Pred>::removeTwoSons(Node<T> *to_remove, Node<T> *p, bool is_right) {
    //to_remove->left < to_remove < to_remove->right --> max_n != to_remove != min_n

    bool is_son = true;
    Node<T>* to_switch = to_remove->right;
    while(to_switch->left != nullptr)
    {
        is_son = false;
        to_switch = to_switch->left;
    }

    Node<T>* to_switch_p = to_switch->parent;
    Node<T>* to_switch_r = to_switch->right;
    Node<T>* to_remove_r = to_remove->right;

    if(p == nullptr)
    {
        to_switch->parent = nullptr;
        root = to_switch;

    }
    else
    {
        to_switch->parent = p;
        if(is_right)
            p->right = to_switch;
        else
            p->left = to_switch;
    }

    if(is_son)
    {
        to_remove->parent = to_switch;
        to_switch->right = to_remove;
    }
    else
    {
        to_remove->parent = to_switch_p;
        to_switch_p->left = to_remove;
        to_switch->right =to_remove_r;
        to_remove_r->parent = to_switch;
    }
    to_switch->left = to_remove->left;
    to_remove->left->parent =to_switch;
    to_remove->left = nullptr;
    to_remove->right = to_switch_r;
    if(to_switch_r != nullptr)
        to_switch_r->parent = to_remove;

    //is_son==true -> to_remove is the right son
    if(to_remove->isALeaf())
        removeLeaf(to_remove,to_remove->parent,is_son);
    else
    {
        removeOneSonRight(to_remove,to_remove->parent,is_son);
    }
}

template<class T, class Pred>
void AvlTree<T,Pred>::fixBalance(Node<T>* from)
{
    Node<T>* temp = from;
    while (temp!= nullptr)
    {
        temp->calcHeight();
        if(temp->getBalance() > 1)
        {
            if(temp->left->getBalance() >= 0)
            {
                LL(temp);
            }
            else{
                LR(temp);
            }
        } else if(temp->getBalance() < -1)
        {
            if(temp->right->getBalance() <= 0)
            {
                RR(temp);
            } else {
                RL(temp);
            }
        }
        temp = temp->parent;
    }
}

template<class T, class Pred>
void AvlTree<T,Pred>::LL( Node<T>* rotation_root)
{
    Node<T>* rotrootParent = rotation_root->parent;
    Node<T>* switch_with = rotation_root->left;
    Node<T>* T2 = switch_with->right;

    //make rotroot.left -> switch.right
    rotation_root->left = T2;
    if(T2!= nullptr)
        T2->parent = rotation_root;

    // make switch.right -> rotroot
    switch_with->right = rotation_root;
    rotation_root->parent = switch_with;

    switch_with->parent = rotrootParent;

    // fix rotrootParent child
    if(rotation_root == root)
    {
        root = switch_with;
    }
    else
    {
        if (rotrootParent->left == rotation_root) {
            rotrootParent->left = switch_with;
        }
        else {
            rotrootParent->right =  switch_with;
        }
    }

    rotation_root->calcHeight();
    switch_with->calcHeight();
}

template<class T, class Pred>
void AvlTree<T,Pred>::RR( Node<T>* rotation_root)
{
    Node<T>* rotrootParent = rotation_root->parent;
    Node<T>* switch_with = rotation_root->right;
    Node<T>* T2 = switch_with->left;

    //make rotroot.right -> switch.left
    rotation_root->right = T2;
    if(T2!= nullptr)
        T2->parent = rotation_root;

    // make switch.left -> rotroot
    switch_with->left = rotation_root;
    rotation_root->parent = switch_with;

    switch_with->parent = rotrootParent;

    // fix rotrootParent child
    if(rotation_root == root)
    {
        root = switch_with;
    }
    else
    {
        if (rotrootParent->left == rotation_root) {
            rotrootParent->left = switch_with;
        }
        else {
            rotrootParent->right =  switch_with;
        }
    }

    rotation_root->calcHeight();
    switch_with->calcHeight();
}

template<class T, class Pred>
void AvlTree<T,Pred>::LR( Node<T>* rotation_root)
{
    RR(rotation_root->left);
    LL(rotation_root);
}

template<class T, class Pred>
void AvlTree<T,Pred>::RL( Node<T>* rotation_root)
{
    LL(rotation_root->right);
    RR(rotation_root);
}


template<class T, class Pred>
void storeInOrder( Node<T>* root, T arr[], int *ind)
{
    if( root == nullptr)
        return;

    storeInOrder<T,Pred>(root->left, arr, ind);

    arr[*ind] = *(root->data);
    (*ind)++;

    storeInOrder<T,Pred>(root->right, arr, ind);
}

template<class T, class Pred>
Node<T>* sortedArrayToRoot(T arr[], int start , int end)
{
    if(start > end)
        return nullptr;
    int mid = (int)((start+end)/2);
    Node<T> *root = newNode(arr[mid]);

    root->left = sortedArrayToRoot<T,Pred>(arr, start, mid-1);
    root->right = sortedArrayToRoot<T,Pred>(arr, mid+1 , end);

    calcNodeHeight(root);

    return  root;
}


template<class T>
Node<T>* fromArrToNodes(Node<T>*& root, Node<T>* ab_arr[], int start, int end)
{
    if(start > end)
        return nullptr;
    int mid = (int)((start + end)/2);
    root = ab_arr[mid];

    root->right = fromArrToNodes(root->left, ab_arr, mid+1 , end);
    if(root->right != nullptr)
        root->right->parent = root;
    root->left = fromArrToNodes(root->left, ab_arr, start, mid-1);
    if(root->left != nullptr)
        root->left->parent = root;


    calcNodeHeight(root);
    return  root;
}

template<class T , class  Pred>
void AvlTree<T,Pred>::merge(AvlTree<T, Pred> &source) {
    Node<T>** arr1 = new Node<T>*[size];
    Node<T>** arr2 = new Node<T>*[source.size];
    int i =0 , j=0;
    AvlTreeToArr<T>(this->root, arr1, &i);
    AvlTreeToArr<T>(source.root, arr2, &j);
    Node<T>** merged_arr = new Node<T>*[size + source.size];
    margeNodeArr(arr1, size , arr2, source.size , merged_arr , a_bigger_b);
    fromArrToNodes<T>(root , merged_arr , 0 , size + source.size - 1);
    if(min_n == nullptr)
    {
        min_n = source.min_n;
    }
    else if(source.min_n != nullptr)
    {
        min_n =(a_bigger_b(*(source.min_n->data),*(min_n->data)) ? min_n: source.min_n);
    }
    if(max_n == nullptr)
    {
        max_n = source.max_n;
    }
    else if(source.max_n != nullptr)
    {
        max_n = (a_bigger_b(*(max_n->data),*(source.max_n->data)) ? max_n: source.max_n);
    }
    size += source.size;

    delete[] arr1;
    delete[] arr2;
    delete[] merged_arr;

}



template<class T, class Pred>
void margeNodeArr(Node<T>* a_arr[], int a_size, Node<T>* b_arr[], int b_size, Node<T>* ab_arr[], Pred cond)
{
    int it_a =0;
    int it_b =0;
    int it_ab =0;
    while(it_a < a_size && it_b < b_size)
    {
        if(cond(*(a_arr[it_a]->data), *(b_arr[it_b]->data)))
        {
            ab_arr[it_ab] = b_arr[it_b];
            it_b++;
            it_ab++;
        }
        else{
            ab_arr[it_ab] =a_arr[it_a];
            it_a++;
            it_ab++;
        }
    }

    while (it_a < a_size)
    {
        ab_arr[it_ab] = a_arr[it_a];
        it_ab++;
        it_a++;
    }

    while (it_b < b_size)
    {
        ab_arr[it_ab] =b_arr[it_b];
        it_b++;
        it_ab++;
    }
}



template<class T>
void AvlTreeToArr(Node<T>* root, Node<T>* arr[], int* loc)
{
    if(root == nullptr)
        return;

    Node<T>* left = root->left;
    Node<T>* right = root->right;

    AvlTreeToArr<T>( left, arr, loc);

    root->right = nullptr;
    root->left = nullptr;
    root->parent = nullptr;
    root->height = 0;

    arr[*loc] = root;
    (*loc)++;
    AvlTreeToArr<T>( right ,arr ,loc);
}


#endif //HW1_AVLTREE2_H