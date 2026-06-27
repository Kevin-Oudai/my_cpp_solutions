#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <vector>

template<typename T>
class AVLTreeNode
{
public:
    T element;
    AVLTreeNode<T>* left;
    AVLTreeNode<T>* right;
    AVLTreeNode<T>* parent;
    int height;
    int size;

    AVLTreeNode(T element)
    {
        this->element = element;
        left = NULL;
        right = NULL;
        parent = NULL;
        height = 1;
        size = 1;
    }
};

template<typename T>
class AVLTree
{
public:
    AVLTree();
    AVLTree(const AVLTree<T>& tree);
    ~AVLTree();
    AVLTree<T>& operator=(const AVLTree<T>& tree);

    bool search(T element) const;
    bool insert(T element);
    bool remove(T element);
    void inorder() const;
    void preorder() const;
    void postorder() const;
    int getSize() const;
    int height() const;
    void clear();
    void displayLeafPaths() const;
    T find(int k) const;
    T getMinimum() const;
    std::vector<T> toVector() const;

private:
    AVLTreeNode<T>* root;
    int treeSize;

    AVLTreeNode<T>* copy(AVLTreeNode<T>* node, AVLTreeNode<T>* parent);
    AVLTreeNode<T>* insert(AVLTreeNode<T>* node, AVLTreeNode<T>* parent, T element, bool& inserted);
    AVLTreeNode<T>* remove(AVLTreeNode<T>* node, T element, bool& removed);
    AVLTreeNode<T>* rebalance(AVLTreeNode<T>* node);
    AVLTreeNode<T>* rotateLeft(AVLTreeNode<T>* node);
    AVLTreeNode<T>* rotateRight(AVLTreeNode<T>* node);
    AVLTreeNode<T>* findMinNode(AVLTreeNode<T>* node) const;
    int nodeHeight(AVLTreeNode<T>* node) const;
    int nodeSize(AVLTreeNode<T>* node) const;
    void update(AVLTreeNode<T>* node);
    int balanceFactor(AVLTreeNode<T>* node) const;
    void inorder(AVLTreeNode<T>* node) const;
    void preorder(AVLTreeNode<T>* node) const;
    void postorder(AVLTreeNode<T>* node) const;
    void clear(AVLTreeNode<T>* node);
    void displayLeafPaths(AVLTreeNode<T>* node, std::vector<T>& path) const;
    T find(int k, AVLTreeNode<T>* node) const;
    void toVector(AVLTreeNode<T>* node, std::vector<T>& values) const;
};

template<typename T>
AVLTree<T>::AVLTree()
{
    root = NULL;
    treeSize = 0;
}

template<typename T>
AVLTree<T>::AVLTree(const AVLTree<T>& tree)
{
    root = copy(tree.root, NULL);
    treeSize = tree.treeSize;
}

template<typename T>
AVLTree<T>::~AVLTree()
{
    clear();
}

template<typename T>
AVLTree<T>& AVLTree<T>::operator=(const AVLTree<T>& tree)
{
    if (this != &tree)
    {
        clear();
        root = copy(tree.root, NULL);
        treeSize = tree.treeSize;
    }

    return *this;
}

template<typename T>
bool AVLTree<T>::search(T element) const
{
    AVLTreeNode<T>* current = root;

    while (current != NULL)
    {
        if (element < current->element)
            current = current->left;
        else if (element > current->element)
            current = current->right;
        else
            return true;
    }

    return false;
}

template<typename T>
bool AVLTree<T>::insert(T element)
{
    bool inserted = false;
    root = insert(root, NULL, element, inserted);

    if (root != NULL)
        root->parent = NULL;

    return inserted;
}

template<typename T>
bool AVLTree<T>::remove(T element)
{
    bool removed = false;
    root = remove(root, element, removed);

    if (root != NULL)
        root->parent = NULL;

    return removed;
}

template<typename T>
void AVLTree<T>::inorder() const
{
    inorder(root);
}

template<typename T>
void AVLTree<T>::preorder() const
{
    preorder(root);
}

template<typename T>
void AVLTree<T>::postorder() const
{
    postorder(root);
}

template<typename T>
int AVLTree<T>::getSize() const
{
    return treeSize;
}

template<typename T>
int AVLTree<T>::height() const
{
    return nodeHeight(root);
}

template<typename T>
void AVLTree<T>::clear()
{
    clear(root);
    root = NULL;
    treeSize = 0;
}

template<typename T>
void AVLTree<T>::displayLeafPaths() const
{
    std::vector<T> path;
    displayLeafPaths(root, path);
}

template<typename T>
T AVLTree<T>::find(int k) const
{
    if (k < 1 || k > treeSize)
        return T();

    return find(k, root);
}

template<typename T>
T AVLTree<T>::getMinimum() const
{
    AVLTreeNode<T>* node = findMinNode(root);

    if (node == NULL)
        return T();

    return node->element;
}

template<typename T>
std::vector<T> AVLTree<T>::toVector() const
{
    std::vector<T> values;
    toVector(root, values);
    return values;
}

template<typename T>
AVLTreeNode<T>* AVLTree<T>::copy(AVLTreeNode<T>* node, AVLTreeNode<T>* parent)
{
    if (node == NULL)
        return NULL;

    AVLTreeNode<T>* newNode = new AVLTreeNode<T>(node->element);
    newNode->parent = parent;
    newNode->height = node->height;
    newNode->size = node->size;
    newNode->left = copy(node->left, newNode);
    newNode->right = copy(node->right, newNode);
    return newNode;
}

template<typename T>
AVLTreeNode<T>* AVLTree<T>::insert(AVLTreeNode<T>* node, AVLTreeNode<T>* parent, T element, bool& inserted)
{
    if (node == NULL)
    {
        inserted = true;
        treeSize++;
        AVLTreeNode<T>* newNode = new AVLTreeNode<T>(element);
        newNode->parent = parent;
        return newNode;
    }

    if (element < node->element)
        node->left = insert(node->left, node, element, inserted);
    else if (element > node->element)
        node->right = insert(node->right, node, element, inserted);
    else
        return node;

    return rebalance(node);
}

template<typename T>
AVLTreeNode<T>* AVLTree<T>::remove(AVLTreeNode<T>* node, T element, bool& removed)
{
    if (node == NULL)
        return NULL;

    if (element < node->element)
    {
        node->left = remove(node->left, element, removed);
        if (node->left != NULL)
            node->left->parent = node;
    }
    else if (element > node->element)
    {
        node->right = remove(node->right, element, removed);
        if (node->right != NULL)
            node->right->parent = node;
    }
    else
    {
        removed = true;

        if (node->left == NULL || node->right == NULL)
        {
            AVLTreeNode<T>* child = node->left != NULL ? node->left : node->right;

            if (child != NULL)
                child->parent = node->parent;

            delete node;
            treeSize--;
            return child;
        }

        AVLTreeNode<T>* successor = findMinNode(node->right);
        node->element = successor->element;
        bool successorRemoved = false;
        node->right = remove(node->right, successor->element, successorRemoved);
        if (node->right != NULL)
            node->right->parent = node;
    }

    return rebalance(node);
}

template<typename T>
AVLTreeNode<T>* AVLTree<T>::rebalance(AVLTreeNode<T>* node)
{
    update(node);
    int balance = balanceFactor(node);

    if (balance > 1)
    {
        if (balanceFactor(node->left) < 0)
            node->left = rotateLeft(node->left);

        return rotateRight(node);
    }

    if (balance < -1)
    {
        if (balanceFactor(node->right) > 0)
            node->right = rotateRight(node->right);

        return rotateLeft(node);
    }

    return node;
}

template<typename T>
AVLTreeNode<T>* AVLTree<T>::rotateLeft(AVLTreeNode<T>* node)
{
    AVLTreeNode<T>* rightChild = node->right;
    AVLTreeNode<T>* rightLeft = rightChild->left;

    rightChild->left = node;
    rightChild->parent = node->parent;
    node->parent = rightChild;
    node->right = rightLeft;

    if (rightLeft != NULL)
        rightLeft->parent = node;

    update(node);
    update(rightChild);
    return rightChild;
}

template<typename T>
AVLTreeNode<T>* AVLTree<T>::rotateRight(AVLTreeNode<T>* node)
{
    AVLTreeNode<T>* leftChild = node->left;
    AVLTreeNode<T>* leftRight = leftChild->right;

    leftChild->right = node;
    leftChild->parent = node->parent;
    node->parent = leftChild;
    node->left = leftRight;

    if (leftRight != NULL)
        leftRight->parent = node;

    update(node);
    update(leftChild);
    return leftChild;
}

template<typename T>
AVLTreeNode<T>* AVLTree<T>::findMinNode(AVLTreeNode<T>* node) const
{
    while (node != NULL && node->left != NULL)
        node = node->left;

    return node;
}

template<typename T>
int AVLTree<T>::nodeHeight(AVLTreeNode<T>* node) const
{
    return node == NULL ? 0 : node->height;
}

template<typename T>
int AVLTree<T>::nodeSize(AVLTreeNode<T>* node) const
{
    return node == NULL ? 0 : node->size;
}

template<typename T>
void AVLTree<T>::update(AVLTreeNode<T>* node)
{
    if (node == NULL)
        return;

    int leftHeight = nodeHeight(node->left);
    int rightHeight = nodeHeight(node->right);
    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    node->size = nodeSize(node->left) + nodeSize(node->right) + 1;

    if (node->left != NULL)
        node->left->parent = node;
    if (node->right != NULL)
        node->right->parent = node;
}

template<typename T>
int AVLTree<T>::balanceFactor(AVLTreeNode<T>* node) const
{
    return node == NULL ? 0 : nodeHeight(node->left) - nodeHeight(node->right);
}

template<typename T>
void AVLTree<T>::inorder(AVLTreeNode<T>* node) const
{
    if (node == NULL)
        return;

    inorder(node->left);
    std::cout << node->element << " ";
    inorder(node->right);
}

template<typename T>
void AVLTree<T>::preorder(AVLTreeNode<T>* node) const
{
    if (node == NULL)
        return;

    std::cout << node->element << " ";
    preorder(node->left);
    preorder(node->right);
}

template<typename T>
void AVLTree<T>::postorder(AVLTreeNode<T>* node) const
{
    if (node == NULL)
        return;

    postorder(node->left);
    postorder(node->right);
    std::cout << node->element << " ";
}

template<typename T>
void AVLTree<T>::clear(AVLTreeNode<T>* node)
{
    if (node == NULL)
        return;

    clear(node->left);
    clear(node->right);
    delete node;
}

template<typename T>
void AVLTree<T>::displayLeafPaths(AVLTreeNode<T>* node, std::vector<T>& path) const
{
    if (node == NULL)
        return;

    path.push_back(node->element);

    if (node->left == NULL && node->right == NULL)
    {
        std::cout << "Leaf path: ";
        for (int i = 0; i < static_cast<int>(path.size()); i++)
            std::cout << path[i] << " ";
        std::cout << std::endl;
    }
    else
    {
        displayLeafPaths(node->left, path);
        displayLeafPaths(node->right, path);
    }

    path.pop_back();
}

template<typename T>
T AVLTree<T>::find(int k, AVLTreeNode<T>* node) const
{
    int leftSize = nodeSize(node->left);

    if (k <= leftSize)
        return find(k, node->left);

    if (k == leftSize + 1)
        return node->element;

    return find(k - leftSize - 1, node->right);
}

template<typename T>
void AVLTree<T>::toVector(AVLTreeNode<T>* node, std::vector<T>& values) const
{
    if (node == NULL)
        return;

    toVector(node->left, values);
    values.push_back(node->element);
    toVector(node->right, values);
}

#endif
