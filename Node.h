#ifndef HW1_NODE_H
#define HW1_NODE_H

template<class T>
class Node {
public:
    T* data;
    Node *right;
    Node *left;
    Node *parent;
    int height;

    int getBalance() const
    {
        int l_h =-1;
        int r_h =-1;
        if(left != nullptr)
            l_h=left->height;
        if(right!= nullptr)
            r_h = right->height;
        return l_h-r_h;
    }

    int calcHeight()
    {
        int l_h = -1;
        int r_h =-1;
        if(left != nullptr)
            l_h = left->height;
        if(right!= nullptr)
            r_h = right->height;
        int n_height = (l_h<r_h ? r_h+1:l_h+1);
        height = n_height;
        return height;
    }

    Node(): data(nullptr), right(nullptr), left(nullptr), parent(nullptr), height(0) {}

    Node(const T& n_data) : data(nullptr), right(nullptr), left(nullptr), parent(nullptr) , height(0){
        data = new T(n_data);
    }

    virtual ~Node() {
        delete left;
        delete right;
        delete data;
    }

    bool isALeaf() const
    {
        return (left == nullptr && right == nullptr);
    }
};

template<class T>
void deleteOnlyThisNodePtr(Node<T>* node)
{
    if(node == nullptr)
        return;
    node->left = nullptr;
    node->right = nullptr;
    node->parent = nullptr;
    delete node;
}

template<class T>
void deleteNodePtr(Node<T>* node)
{
    if(node == nullptr)
        return;
    delete node;
}

template<class T>
Node<T>* newNode(T& n_data)
{
    Node<T>* node = new Node<T>(n_data);
    node->left = nullptr;
    node->right = nullptr;
    node->parent = nullptr;

    return  node;
}

template<class T>
bool NodeIsALeaf(Node<T>* node)
{
    if(node == nullptr)
        return false;
    return node->isALeaf();
}

template<class T>
int calcNodeHeight(Node<T>* node)
{
    if(node == nullptr)
        return -1;
    return node->calcHeight();
}

template<class T>
int getNodesBalance(const Node<T>* node)
{
    if(node == nullptr)
    {
        return 0;
    }
    return  node->getBalance();
}


#endif //HW1_NODE_H
