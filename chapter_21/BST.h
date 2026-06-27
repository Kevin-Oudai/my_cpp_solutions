#ifndef BST_H
#define BST_H

#include <cstddef>
#include <iostream>
#include <vector>

template<typename T>
class TreeNode
{
public:
    T element;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode<T>* parent;

    TreeNode(T element)
    {
        this->element = element;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

template<typename T>
class BSTIterator
{
public:
    BSTIterator()
    {
        current = 0;
    }

    BSTIterator(TreeNode<T>* root)
    {
        current = 0;
        inorder(root);
    }

    BSTIterator operator++()
    {
        current++;
        return *this;
    }

    BSTIterator operator++(int)
    {
        BSTIterator temp(*this);
        current++;
        return temp;
    }

    T& operator*()
    {
        return elements[current];
    }

    bool operator==(const BSTIterator<T>& iterator) const
    {
        return current == iterator.current && elements.size() == iterator.elements.size();
    }

    bool operator!=(const BSTIterator<T>& iterator) const
    {
        return !(*this == iterator);
    }

private:
    std::vector<T> elements;
    int current;

    void inorder(TreeNode<T>* root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        elements.push_back(root->element);
        inorder(root->right);
    }
};

template<typename T>
class BST
{
public:
    BST();
    BST(const T elements[], int arraySize);
    BST(const BST<T>& tree);
    virtual ~BST();
    BST<T>& operator=(const BST<T>& tree);

    bool search(T element) const;
    virtual bool insert(T element);
    virtual bool remove(T element);
    void inorder() const;
    void preorder() const;
    void postorder() const;
    void breadthFirstTraversal() const;
    void inorderWithStack() const;
    void preorderWithStack() const;
    void postorderWithStack() const;
    int height() const;
    int getSize() const;
    int getNumberofLeaves() const;
    int getNumberOfLeaves() const;
    int getNumberofNonLeaves() const;
    int getNumberOfNonLeaves() const;
    bool isFullBST() const;
    void clear();
    std::vector<TreeNode<T>*> path(T element) const;
    void displayLeafPaths() const;
    TreeNode<T>* getParent(TreeNode<T>* node) const;
    TreeNode<T>* getParent(TreeNode<T> node) const;
    TreeNode<T>* findNode(T element) const;

    BSTIterator<T> begin() const
    {
        return BSTIterator<T>(root);
    }

    BSTIterator<T> end() const
    {
        BSTIterator<T> iterator(root);
        for (int i = 0; i < size; i++)
            iterator++;
        return iterator;
    }

protected:
    TreeNode<T>* root;
    int size;

    TreeNode<T>* createNewNode(T element);
    void copy(TreeNode<T>* root);
    void inorder(TreeNode<T>* root) const;
    void preorder(TreeNode<T>* root) const;
    void postorder(TreeNode<T>* root) const;
    int height(TreeNode<T>* root) const;
    int getNumberofLeaves(TreeNode<T>* root) const;
    int getNumberofNonLeaves(TreeNode<T>* root) const;
    void clear(TreeNode<T>* root);
    void displayLeafPaths(TreeNode<T>* root, std::vector<T>& path) const;
    long long fullTreeNodeCount(int levels) const;
};

template<typename T>
BST<T>::BST()
{
    root = NULL;
    size = 0;
}

template<typename T>
BST<T>::BST(const T elements[], int arraySize)
{
    root = NULL;
    size = 0;

    for (int i = 0; i < arraySize; i++)
        insert(elements[i]);
}

template<typename T>
BST<T>::BST(const BST<T>& tree)
{
    root = NULL;
    size = 0;
    copy(tree.root);
}

template<typename T>
BST<T>::~BST()
{
    clear();
}

template<typename T>
BST<T>& BST<T>::operator=(const BST<T>& tree)
{
    if (this != &tree)
    {
        clear();
        copy(tree.root);
    }

    return *this;
}

template<typename T>
bool BST<T>::search(T element) const
{
    TreeNode<T>* current = root;

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
bool BST<T>::insert(T element)
{
    if (root == NULL)
    {
        root = createNewNode(element);
        size++;
        return true;
    }

    TreeNode<T>* parent = NULL;
    TreeNode<T>* current = root;

    while (current != NULL)
    {
        if (element < current->element)
        {
            parent = current;
            current = current->left;
        }
        else if (element > current->element)
        {
            parent = current;
            current = current->right;
        }
        else
        {
            return false;
        }
    }

    TreeNode<T>* newNode = createNewNode(element);
    newNode->parent = parent;

    if (element < parent->element)
        parent->left = newNode;
    else
        parent->right = newNode;

    size++;
    return true;
}

template<typename T>
bool BST<T>::remove(T element)
{
    TreeNode<T>* parent = NULL;
    TreeNode<T>* current = root;

    while (current != NULL)
    {
        if (element < current->element)
        {
            parent = current;
            current = current->left;
        }
        else if (element > current->element)
        {
            parent = current;
            current = current->right;
        }
        else
        {
            break;
        }
    }

    if (current == NULL)
        return false;

    if (current->left == NULL)
    {
        TreeNode<T>* child = current->right;

        if (parent == NULL)
            root = child;
        else if (element < parent->element)
            parent->left = child;
        else
            parent->right = child;

        if (child != NULL)
            child->parent = parent;

        delete current;
    }
    else
    {
        TreeNode<T>* parentOfRightMost = current;
        TreeNode<T>* rightMost = current->left;

        while (rightMost->right != NULL)
        {
            parentOfRightMost = rightMost;
            rightMost = rightMost->right;
        }

        current->element = rightMost->element;

        TreeNode<T>* child = rightMost->left;
        if (parentOfRightMost->right == rightMost)
            parentOfRightMost->right = child;
        else
            parentOfRightMost->left = child;

        if (child != NULL)
            child->parent = parentOfRightMost;

        delete rightMost;
    }

    size--;
    return true;
}

template<typename T>
void BST<T>::inorder() const
{
    inorder(root);
}

template<typename T>
void BST<T>::preorder() const
{
    preorder(root);
}

template<typename T>
void BST<T>::postorder() const
{
    postorder(root);
}

template<typename T>
void BST<T>::breadthFirstTraversal() const
{
    std::vector<TreeNode<T>*> queue;
    int currentIndex = 0;

    if (root != NULL)
        queue.push_back(root);

    while (currentIndex < static_cast<int>(queue.size()))
    {
        TreeNode<T>* current = queue[currentIndex];
        currentIndex++;

        std::cout << current->element << " ";

        if (current->left != NULL)
            queue.push_back(current->left);
        if (current->right != NULL)
            queue.push_back(current->right);
    }
}

template<typename T>
void BST<T>::inorderWithStack() const
{
    std::vector<TreeNode<T>*> stack;
    TreeNode<T>* current = root;

    while (current != NULL || stack.size() > 0)
    {
        while (current != NULL)
        {
            stack.push_back(current);
            current = current->left;
        }

        current = stack[stack.size() - 1];
        stack.pop_back();
        std::cout << current->element << " ";
        current = current->right;
    }
}

template<typename T>
void BST<T>::preorderWithStack() const
{
    std::vector<TreeNode<T>*> stack;

    if (root != NULL)
        stack.push_back(root);

    while (stack.size() > 0)
    {
        TreeNode<T>* current = stack[stack.size() - 1];
        stack.pop_back();

        std::cout << current->element << " ";

        if (current->right != NULL)
            stack.push_back(current->right);
        if (current->left != NULL)
            stack.push_back(current->left);
    }
}

template<typename T>
void BST<T>::postorderWithStack() const
{
    std::vector<TreeNode<T>*> stack;
    TreeNode<T>* current = root;
    TreeNode<T>* lastVisited = NULL;

    while (current != NULL || stack.size() > 0)
    {
        if (current != NULL)
        {
            stack.push_back(current);
            current = current->left;
        }
        else
        {
            TreeNode<T>* peekNode = stack[stack.size() - 1];
            if (peekNode->right != NULL && lastVisited != peekNode->right)
            {
                current = peekNode->right;
            }
            else
            {
                std::cout << peekNode->element << " ";
                lastVisited = peekNode;
                stack.pop_back();
            }
        }
    }
}

template<typename T>
int BST<T>::height() const
{
    return height(root);
}

template<typename T>
int BST<T>::getSize() const
{
    return size;
}

template<typename T>
int BST<T>::getNumberofLeaves() const
{
    return getNumberofLeaves(root);
}

template<typename T>
int BST<T>::getNumberOfLeaves() const
{
    return getNumberofLeaves();
}

template<typename T>
int BST<T>::getNumberofNonLeaves() const
{
    return getNumberofNonLeaves(root);
}

template<typename T>
int BST<T>::getNumberOfNonLeaves() const
{
    return getNumberofNonLeaves();
}

template<typename T>
bool BST<T>::isFullBST() const
{
    return size == fullTreeNodeCount(height());
}

template<typename T>
void BST<T>::clear()
{
    clear(root);
    root = NULL;
    size = 0;
}

template<typename T>
std::vector<TreeNode<T>*> BST<T>::path(T element) const
{
    std::vector<TreeNode<T>*> path;
    TreeNode<T>* current = root;

    while (current != NULL)
    {
        path.push_back(current);

        if (element < current->element)
            current = current->left;
        else if (element > current->element)
            current = current->right;
        else
            break;
    }

    return path;
}

template<typename T>
void BST<T>::displayLeafPaths() const
{
    std::vector<T> currentPath;
    displayLeafPaths(root, currentPath);
}

template<typename T>
TreeNode<T>* BST<T>::getParent(TreeNode<T>* node) const
{
    if (node == NULL)
        return NULL;

    return node->parent;
}

template<typename T>
TreeNode<T>* BST<T>::getParent(TreeNode<T> node) const
{
    TreeNode<T>* found = findNode(node.element);

    if (found == NULL)
        return NULL;

    return found->parent;
}

template<typename T>
TreeNode<T>* BST<T>::findNode(T element) const
{
    TreeNode<T>* current = root;

    while (current != NULL)
    {
        if (element < current->element)
            current = current->left;
        else if (element > current->element)
            current = current->right;
        else
            return current;
    }

    return NULL;
}

template<typename T>
TreeNode<T>* BST<T>::createNewNode(T element)
{
    return new TreeNode<T>(element);
}

template<typename T>
void BST<T>::copy(TreeNode<T>* root)
{
    if (root == NULL)
        return;

    insert(root->element);
    copy(root->left);
    copy(root->right);
}

template<typename T>
void BST<T>::inorder(TreeNode<T>* root) const
{
    if (root == NULL)
        return;

    inorder(root->left);
    std::cout << root->element << " ";
    inorder(root->right);
}

template<typename T>
void BST<T>::preorder(TreeNode<T>* root) const
{
    if (root == NULL)
        return;

    std::cout << root->element << " ";
    preorder(root->left);
    preorder(root->right);
}

template<typename T>
void BST<T>::postorder(TreeNode<T>* root) const
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    std::cout << root->element << " ";
}

template<typename T>
int BST<T>::height(TreeNode<T>* root) const
{
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;

    return rightHeight + 1;
}

template<typename T>
int BST<T>::getNumberofLeaves(TreeNode<T>* root) const
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return getNumberofLeaves(root->left) + getNumberofLeaves(root->right);
}

template<typename T>
int BST<T>::getNumberofNonLeaves(TreeNode<T>* root) const
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 0;

    return 1 + getNumberofNonLeaves(root->left) + getNumberofNonLeaves(root->right);
}

template<typename T>
void BST<T>::clear(TreeNode<T>* root)
{
    if (root == NULL)
        return;

    clear(root->left);
    clear(root->right);
    delete root;
}

template<typename T>
void BST<T>::displayLeafPaths(TreeNode<T>* root, std::vector<T>& path) const
{
    if (root == NULL)
        return;

    path.push_back(root->element);

    if (root->left == NULL && root->right == NULL)
    {
        std::cout << "Leaf path: ";
        for (int i = 0; i < static_cast<int>(path.size()); i++)
            std::cout << path[i] << " ";
        std::cout << std::endl;
    }
    else
    {
        displayLeafPaths(root->left, path);
        displayLeafPaths(root->right, path);
    }

    path.pop_back();
}

template<typename T>
long long BST<T>::fullTreeNodeCount(int levels) const
{
    long long result = 1;

    for (int i = 0; i < levels; i++)
    {
        result *= 2;
        if (result > size + 1)
            return result - 1;
    }

    return result - 1;
}

#endif
