//
// Created by lenovo on 27/04/2022.
//

#ifndef HW1_DELETE_H
#define HW1_DELETE_H

#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "exceptions.h"
#include <iostream>
using namespace std;

//----------------------- Generic AVL Tree -----------------------//

template<class T>
class AVLTree {
private:
    // Tree fields
    struct Node {
        Node *right;
        Node *left;
        Node *father;
        int height;
        T* data;
    };
    Node *root;
    Node *min;
    Node *max;
    int size;

    // Node Functions
    Node* initNode(const T& data);
    Node* insertNode(Node *node, Node *target, Node *father);
    Node* findNode(Node *node, const T& data);
    Node* removeNode(Node *node, Node *target);
    Node* getMin(Node *node) const;
    Node* getMax(Node *node) const;
    int balanceFactor(Node *node) const;
    int height(const Node* node) const;
    T* getNodeData(Node* node) const;

    // Roll Functions
    Node *rollLeftLeft(Node *node);
    Node *rollLeftRight(Node *node);
    Node *rollRightLeft(Node *node);
    Node *rollRightRight(Node *node);

    // Constructor, Destructor helper functions
    Node* sortedInit_aux(T data_arr[], int start, int end, AVLTree<T>::Node* father);
    Node* copyNode(Node* node);
    void empty_aux(Node* node);

    // Aux functions

public:
    // Constructors, Destructor, Assignment
    AVLTree();
    AVLTree(const AVLTree<T>& tree);
    AVLTree &operator=(const AVLTree<T> &tree);
    void sortedArrayInit(T data_arr[], int n);
    ~AVLTree();

    // Interface Functions
    void insert(const T& data);
    T* find(const T& data);
    void remove(const T& data);
    int getHeight() const;
    void empty();
    bool isEmpty() const;
    T* getMaxData() const;

    //------------ Iterator ------------//
    class AvlIterator{
        Node* node;
        Node* max;
    public:
        AvlIterator(Node* node, Node* max);
        ~AvlIterator() = default;
        AvlIterator& operator=(const AvlIterator& avl_iterator);
        AvlIterator(const AvlIterator& avl_iterator);

        T* operator*();
        AvlIterator& operator++();
        bool operator==(const AvlIterator& avl_iterator) const;
        bool operator!=(const AvlIterator& avl_iterator) const;

        friend class AVLTree<T>;
    };
    AvlIterator begin() const;
    AvlIterator end() const;
    //---------------------------//
};

static int maxInt(int num1, int num2);

// Constructors, Destructor, Assignment ---------------------

template<class T>
AVLTree<T>::AVLTree() : root(NULL), min(NULL), max(NULL), size(0) {
}

template<class T>
AVLTree<T>::~AVLTree(){
    empty();
}

template<class T>
AVLTree<T>::AVLTree(const AVLTree<T>& tree):root(NULL), min(NULL), max(NULL), size(0){
    root = copyNode(tree.root);
    size = tree.size;
    min = getMin(root);
    max = getMax(root);
}

template<class T>
AVLTree<T>& AVLTree<T>::operator=(const AVLTree<T> &tree){
    empty();
    root = copyNode(tree.root);
    size = tree.size;
    min = getMin(root);
    max = getMax(root);
    return *this;
}

template<class T>
void AVLTree<T>::sortedArrayInit(T data_arr[], int n) {
    if(size > 0)
        throw TreeHasData();
    root = sortedInit_aux(data_arr, 0, n - 1, NULL);
    size = n;
    min = getMin(root);
    max = getMax(root);
}

// Interface Functions -------------------------------

template<class T>
void AVLTree<T>::insert(const T& data) {
    if (&data == NULL) {
        return;
    }
    if (findNode(root, data) != NULL) {
        throw NodeExists();
    }

    Node *node = initNode(data);

    root = insertNode(node, root, NULL);
    min = getMin(root);
    max = getMax(root);
    size++;
}

template<class T>
T* AVLTree<T>::find(const T& data){
    Node* node = findNode(root, data);
    if(node == NULL)
        throw NodeDoesntExist();
    return node->data;
}

template<class T>
void AVLTree<T>::remove(const T& data) {
    if (&data == NULL || size == 0) {
        return;
    }
    Node* node_to_remove = findNode(root, data);

    if (node_to_remove == NULL) {
        throw NodeDoesntExist();
    }

    root = removeNode(node_to_remove, root);
    min = getMin(root);
    max = getMax(root);
    size--;
}

template<class T>
void AVLTree<T>::empty() {
    if(size > 0){
        empty_aux(root);
        root = NULL;
        size = 0;
        min = NULL;
        max = NULL;
    }

}

template<class T>
int AVLTree<T>::getHeight()const{
    if (root == NULL) {
        return 0;
    }
    return root->height;
}

template<class T>
bool AVLTree<T>::isEmpty() const{
    return size == 0;
}

template<class T>
T* AVLTree<T>::getMaxData() const{
    return getNodeData(max);
}

// Node Functions ---------------------------------------------

template<class T>
typename AVLTree<T>::Node* AVLTree<T>::initNode(const T& data){
    Node* node = new Node;
    node->data = new T(data);
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
    node->father = NULL;
    return node;
}

template<class T>
typename AVLTree<T>::Node*
AVLTree<T>::insertNode(AVLTree<T>::Node *node, AVLTree<T>::Node *target, AVLTree<T>::Node *father) {
    //Inserting the node
    if (target == NULL) {
        node->father = father;
        return node;
    }

    if (*node->data < *target->data) {
        target->left = insertNode(node, target->left, target);
    } else {
        target->right = insertNode(node, target->right, target);
    }

    //Balancing the tree
    if (balanceFactor(target) > 1) {
        if (balanceFactor(target->left) >= 0) {
            return rollLeftLeft(target); //LL
        } else {
            return rollLeftRight(target);//LR
        }
    } else if (balanceFactor(target) < -1) {
        if (balanceFactor(target->right) == 1) {
            return rollRightLeft(target); //RL
        } else {
            return rollRightRight(target); //RR
        }
    }
    target->height = maxInt(height(target->right), height(target->left)) + 1;
    return target;
}

template<class T>
typename AVLTree<T>::Node* AVLTree<T>::removeNode(AVLTree<T>::Node *node, AVLTree<T>::Node *target) {
    if (node == NULL) {
        return NULL;
    }
    // Delete the node
    if (*node->data == *target->data) {
        if (!target->right && !target->left) {
            // Leaf
            delete target->data;
            delete target;
            return NULL;
        } else if (!target->right) {
            // Only left son
            Node* temp = target->left;
            delete target->data;
            target->data = new T(*temp->data);
            target->left = removeNode(target, target->left);

        } else if (!target->left) {
            // Only right son
            Node* temp = target->right;
            delete target->data;
            target->data = new T(*temp->data);
            target->right = removeNode(target, target->right);
        } else {
            // right and left son exist
            Node *temp = getMin(target->right);
            delete target->data;
            target->data = new T(*temp->data);
            target->right = removeNode(target, target->right);
        }
    } else if (*node->data < *target->data) {
        target->left = removeNode(node, target->left);
    } else {
        target->right = removeNode(node, target->right);
    }


    target->height = maxInt(height(target->left), height(target->right)) + 1;

    // Balancing the tree
    if (balanceFactor(target) > 1) {
        if (balanceFactor(target->left) >= 0) {
            return rollLeftLeft(target); //LL
        } else {
            return rollLeftRight(target);//LR
        }
    } else if (balanceFactor(target) < -1) {
        if (balanceFactor(target->right) == 1) {
            return rollRightLeft(target); //RL
        } else {
            return rollRightRight(target); //RR
        }
    }
    return target;
}

template<class T>
typename AVLTree<T>::Node* AVLTree<T>::findNode(AVLTree<T>::Node* node, const T& data){
    if(node == NULL)
        return NULL;
    if (data == *node->data) {
        return node;
    } else {
        if (data > *node->data) {
            return findNode(node->right, data);
        } else {
            return findNode(node->left, data);
        }
    }
}

template<class T>
int AVLTree<T>::balanceFactor(AVLTree<T>::Node *node) const {
    return height(node->left) - height(node->right);
}

template<class T>
int AVLTree<T>::height(const Node* node) const{
    return node == NULL ? -1 : node->height;
}


template<class T>
typename AVLTree<T>::Node* AVLTree<T>::getMin(AVLTree<T>::Node* node) const{
    if (node == NULL) {
        return NULL;
    }
    if (node->left == NULL) {
        return node;
    }

    return getMin(node->left);
}

template<class T>
typename AVLTree<T>::Node* AVLTree<T>::getMax(Node *node) const{
    if (node == NULL) {
        return NULL;
    }
    if (node->right == NULL) {
        return node;
    }

    return getMax(node->right);
}

template<class T>
T* AVLTree<T>::getNodeData(Node* node) const{
    return node->data;
}

// Roll Functions------------------------------

template<class T>
typename AVLTree<T>::Node *AVLTree<T>::rollLeftLeft(AVLTree<T>::Node *node) {
    Node *temp = node->left;
    node->left->father = node->father;
    node->father = temp;
    if(temp->right){
        temp->right->father =node;
    }
    node->left = node->father->right;
    node->father->right = node;
    node->height = maxInt(height(node->right), height(node->left)) + 1;
    if(node->father) {
        node->father->height = maxInt(height(node->father->right), height(node->father->left)) + 1;
    }
    return node->father;
}

template<class T>
typename AVLTree<T>::Node *AVLTree<T>::rollRightRight(AVLTree<T>::Node *node) {
    Node *temp = node->right;
    node->right->father = node->father;
    node->father = temp;
    node->right = node->father->left;
    if(node->right)
        node->right->father = node;
    node->father->left = node;

    node->height = maxInt(height(node->right), height(node->left)) + 1;
    if(node->father){
        node->father->height = maxInt(height(node->father->right), height(node->father->left)) + 1;
    }

    return node->father;
}

template<class T>
typename AVLTree<T>::Node *AVLTree<T>::rollLeftRight(AVLTree<T>::Node *node) {
    node->left = rollRightRight(node->left);
    return rollLeftLeft(node);
}

template<class T>
typename AVLTree<T>::Node *AVLTree<T>::rollRightLeft(AVLTree<T>::Node *node) {
    node->right = rollLeftLeft(node->right);
    return rollRightRight(node);
}

// Constructor, Destructor helper functions--------------------------------------------

template<class T>
typename AVLTree<T>::Node* AVLTree<T>::sortedInit_aux(T data_arr[], int start, int end, AVLTree<T>::Node* father){
    if(start > end)
        return NULL;

    int mid = (start+end)/2;
    Node *node = initNode(data_arr[mid]);
    node->father = father;
    node->left = sortedInit_aux(data_arr, start, mid -1, node);
    node->right = sortedInit_aux(data_arr, mid + 1, end, node);
    node->height = maxInt(height(node->right), height(node->left)) + 1;
    return node;
}

template<class T>
typename AVLTree<T>::Node* AVLTree<T>::copyNode(AVLTree<T>::Node* node){
    if(node == NULL){
        return NULL;
    }
    Node* left = copyNode(node->left);
    Node* right = copyNode(node->right);

    Node* new_node = initNode(*node->data);
//    new_node->father = node->father;
    new_node->left = left;
    if(new_node->left)
        new_node->left->father = new_node;
    new_node->right = right;
    if(new_node->right)
        new_node->right->father = new_node;
    new_node->height = maxInt(height(new_node->right), height(new_node->left)) + 1;
    return new_node;
}


template<class T>
void AVLTree<T>::empty_aux(AVLTree<T>::Node* node) {
    if(node == NULL){
        return;
    }

    if(node->left){
        empty_aux(node->left);
    }
    if(node->right){
        empty_aux(node->right);
    }
    delete node->data;
    delete node;
}

static int maxInt(int num1, int num2){
    return num1 > num2 ? num1 : num2;
}

//---------------Iterator Implementation-----------//

template<class T>
AVLTree<T>::AvlIterator::AvlIterator(Node* node, Node* max): node(node), max(max){
}

template<class T>
typename AVLTree<T>::AvlIterator& AVLTree<T>::AvlIterator::operator=(const AvlIterator& avl_iterator){
    if(*this == avl_iterator){
        return *this;
    }
    node = avl_iterator.node;
    max = avl_iterator.max;
    return *this;
}

template<class T>
AVLTree<T>::AvlIterator::AvlIterator(const AvlIterator& avl_iterator): node(avl_iterator.node), max(avl_iterator.max){
}

template<class T>
T* AVLTree<T>::AvlIterator::operator*(){
    if(node == NULL){
        return NULL;
    }
    return node->data;
}

template<class T>
typename AVLTree<T>::AvlIterator& AVLTree<T>::AvlIterator::operator++(){
    if(node == max){
        node = NULL;
    }
    else {
        if (node->right != NULL) {
            node = node->right;
            while (node->left != NULL) {
                node = node->left;
            }
        } else {
            Node *temp = node;
            node = node->father;
            while (node->father != NULL && node->right == temp) { //climbed from right son so continue
                temp = node;
                node = node->father;
            }
        }
    }
    return *this;
}

template<class T>
bool AVLTree<T>::AvlIterator::operator==(const AvlIterator& avl_iterator)const{
    return node == avl_iterator.node;
}

template<class T>
bool AVLTree<T>::AvlIterator::operator!=(const AvlIterator& avl_iterator)const{
    return !(*this == avl_iterator);
}

template<class T>
typename AVLTree<T>::AvlIterator AVLTree<T>::begin() const{
    return AvlIterator(min, max);
}

template<class T>
typename AVLTree<T>::AvlIterator AVLTree<T>::end() const{
    return AvlIterator(NULL,NULL);
}

#endif //DS_HW1_AVL_TREE_H

#endif //HW1_DELETE_H
