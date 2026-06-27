#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include "../chapter_21/BST.h"

template<typename T>
class SplayTree : public BST<T>
{
public:
    bool search(T element);
    bool insert(T element);
    bool remove(T element);
    T getRootElement() const;

private:
    void splay(TreeNode<T>* node);
    void rotateLeft(TreeNode<T>* node);
    void rotateRight(TreeNode<T>* node);
    TreeNode<T>* findNodeOrLast(T element);
    TreeNode<T>* subtreeMaximum(TreeNode<T>* node) const;
};

template<typename T>
bool SplayTree<T>::search(T element)
{
    TreeNode<T>* node = findNodeOrLast(element);

    if (node != NULL)
        splay(node);

    return this->root != NULL && this->root->element == element;
}

template<typename T>
bool SplayTree<T>::insert(T element)
{
    if (this->root == NULL)
    {
        this->root = new TreeNode<T>(element);
        this->size++;
        return true;
    }

    TreeNode<T>* parent = NULL;
    TreeNode<T>* current = this->root;

    while (current != NULL)
    {
        parent = current;

        if (element < current->element)
            current = current->left;
        else if (element > current->element)
            current = current->right;
        else
        {
            splay(current);
            return false;
        }
    }

    TreeNode<T>* newNode = new TreeNode<T>(element);
    newNode->parent = parent;

    if (element < parent->element)
        parent->left = newNode;
    else
        parent->right = newNode;

    this->size++;
    splay(newNode);
    return true;
}

template<typename T>
bool SplayTree<T>::remove(T element)
{
    if (!search(element))
        return false;

    TreeNode<T>* oldRoot = this->root;
    TreeNode<T>* leftTree = oldRoot->left;
    TreeNode<T>* rightTree = oldRoot->right;

    if (leftTree != NULL)
        leftTree->parent = NULL;
    if (rightTree != NULL)
        rightTree->parent = NULL;

    oldRoot->left = NULL;
    oldRoot->right = NULL;
    delete oldRoot;
    this->size--;

    if (leftTree == NULL)
    {
        this->root = rightTree;
    }
    else
    {
        this->root = leftTree;
        TreeNode<T>* maximum = subtreeMaximum(leftTree);
        splay(maximum);
        this->root->right = rightTree;

        if (rightTree != NULL)
            rightTree->parent = this->root;
    }

    return true;
}

template<typename T>
T SplayTree<T>::getRootElement() const
{
    if (this->root == NULL)
        return T();

    return this->root->element;
}

template<typename T>
void SplayTree<T>::splay(TreeNode<T>* node)
{
    while (node->parent != NULL)
    {
        TreeNode<T>* parent = node->parent;
        TreeNode<T>* grandparent = parent->parent;

        if (grandparent == NULL)
        {
            if (node == parent->left)
                rotateRight(parent);
            else
                rotateLeft(parent);
        }
        else if (node == parent->left && parent == grandparent->left)
        {
            rotateRight(grandparent);
            rotateRight(parent);
        }
        else if (node == parent->right && parent == grandparent->right)
        {
            rotateLeft(grandparent);
            rotateLeft(parent);
        }
        else if (node == parent->right && parent == grandparent->left)
        {
            rotateLeft(parent);
            rotateRight(grandparent);
        }
        else
        {
            rotateRight(parent);
            rotateLeft(grandparent);
        }
    }

    this->root = node;
}

template<typename T>
void SplayTree<T>::rotateLeft(TreeNode<T>* node)
{
    TreeNode<T>* rightChild = node->right;
    if (rightChild == NULL)
        return;

    node->right = rightChild->left;
    if (rightChild->left != NULL)
        rightChild->left->parent = node;

    rightChild->parent = node->parent;

    if (node->parent == NULL)
        this->root = rightChild;
    else if (node == node->parent->left)
        node->parent->left = rightChild;
    else
        node->parent->right = rightChild;

    rightChild->left = node;
    node->parent = rightChild;
}

template<typename T>
void SplayTree<T>::rotateRight(TreeNode<T>* node)
{
    TreeNode<T>* leftChild = node->left;
    if (leftChild == NULL)
        return;

    node->left = leftChild->right;
    if (leftChild->right != NULL)
        leftChild->right->parent = node;

    leftChild->parent = node->parent;

    if (node->parent == NULL)
        this->root = leftChild;
    else if (node == node->parent->left)
        node->parent->left = leftChild;
    else
        node->parent->right = leftChild;

    leftChild->right = node;
    node->parent = leftChild;
}

template<typename T>
TreeNode<T>* SplayTree<T>::findNodeOrLast(T element)
{
    TreeNode<T>* current = this->root;
    TreeNode<T>* last = NULL;

    while (current != NULL)
    {
        last = current;

        if (element < current->element)
            current = current->left;
        else if (element > current->element)
            current = current->right;
        else
            return current;
    }

    return last;
}

template<typename T>
TreeNode<T>* SplayTree<T>::subtreeMaximum(TreeNode<T>* node) const
{
    while (node != NULL && node->right != NULL)
        node = node->right;

    return node;
}

#endif
