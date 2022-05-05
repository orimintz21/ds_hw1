#ifndef TREE_NODE_H_
#define TREE_NODE_H_

#include <memory>

template<class T>
class TreeNode
{
public:
    T data;
    TreeNode<T>* parent;
    shared_ptr<TreeNode<T>> left;
    shared_ptr<TreeNode<T>> right;
    int height;
    int balance;

    TreeNode();

    TreeNode(T info);
    virtual ~TreeNode() = default;
    int clacBalance() ;
    bool isInBalance() const;
    void calcHeight();
    bool isLeaf() const;
};

template<class T>
TreeNode<T>::TreeNode() : parent(nullptr), left(nullptr), right(nullptr) {}

template<class T>
TreeNode<T>::TreeNode(T info) : data(info) ,parent(nullptr), left(nullptr), right(nullptr) {}

template<class T>
int TreeNode<T>::clacBalance()
{
    int left_height = -1;
    int right_height = -1;

    if(left != nullptr)
    {
        left_height = left->height;
    }
    if(right != nullptr)
    {
        right_height = right->height;
    }
    balance = left_height-right_height;
    return  balance;
}

template<class T>
bool TreeNode<T>::isInBalance() const
{
    if((this->balance <= 1) && (this->balance>=-1))
    {
        return true;
    }
    return false;
}

template<class T>
void TreeNode<T>::calcHeight()
{
    int left_height = -1;
    int right_height = -1;

    if(left != nullptr)
    {
        left_height = left->height;
    }
    if(right != nullptr)
    {
        right_height = right->height;
    }

    if(left_height < right_height)
    {
        height = right_height + 1;
    }else
    {
        height = left_height +1;
    }
    return;

}

template<class T>
bool TreeNode<T>::isLeaf() const
{
    return ((left == nullptr) && (right == nullptr));
}

#endif //TREE_NODE_H_