#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>

template<typename T>
class Node
{
public:
    T element;
    Node<T>* next;

    Node()
    {
        next = NULL;
    }

    Node(T element)
    {
        this->element = element;
        next = NULL;
    }
};

template<typename T>
class Iterator
{
public:
    Iterator(Node<T>* p)
    {
        current = p;
    }

    Iterator operator++()
    {
        current = current->next;
        return *this;
    }

    Iterator operator++(int)
    {
        Iterator temp(current);
        current = current->next;
        return temp;
    }

    T& operator*()
    {
        return current->element;
    }

    bool operator==(const Iterator<T>& iterator) const
    {
        return current == iterator.current;
    }

    bool operator!=(const Iterator<T>& iterator) const
    {
        return current != iterator.current;
    }

private:
    Node<T>* current;
};

template<typename T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(const LinkedList<T>& list);
    virtual ~LinkedList();
    LinkedList<T>& operator=(const LinkedList<T>& list);

    void addFirst(T element);
    void addLast(T element);
    T getFirst() const;
    T getLast() const;
    T removeFirst();
    T removeLast();
    void add(T element);
    void add(int index, T element);
    void clear();
    bool contains(T element) const;
    T get(int index) const;
    int indexOf(T element) const;
    bool isEmpty() const;
    int lastIndexOf(T element) const;
    void remove(T element);
    int getSize() const;
    T removeAt(int index);
    T set(int index, T element);
    void reverse();
    void sort();
    void addAll(LinkedList<T>& otherList);
    void removeAll(LinkedList<T>& otherList);
    void retainAll(LinkedList<T>& otherList);

    LinkedList<T> operator+(LinkedList<T>& otherList) const;
    LinkedList<T> operator-(LinkedList<T>& otherList) const;
    LinkedList<T> operator^(LinkedList<T>& otherList) const;
    T& operator[](int index);

    Iterator<T> begin() const
    {
        return Iterator<T>(head);
    }

    Iterator<T> end() const
    {
        return Iterator<T>(NULL);
    }

protected:
    Node<T>* head;
    Node<T>* tail;
    int size;
    Node<T>* getNode(int index) const;
};

template<typename T>
LinkedList<T>::LinkedList()
{
    head = tail = NULL;
    size = 0;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list)
{
    head = tail = NULL;
    size = 0;

    Node<T>* current = list.head;
    while (current != NULL)
    {
        add(current->element);
        current = current->next;
    }
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& list)
{
    if (this != &list)
    {
        clear();
        Node<T>* current = list.head;
        while (current != NULL)
        {
            add(current->element);
            current = current->next;
        }
    }

    return *this;
}

template<typename T>
void LinkedList<T>::addFirst(T element)
{
    Node<T>* newNode = new Node<T>(element);
    newNode->next = head;
    head = newNode;
    size++;

    if (tail == NULL)
        tail = head;
}

template<typename T>
void LinkedList<T>::addLast(T element)
{
    if (tail == NULL)
    {
        head = tail = new Node<T>(element);
    }
    else
    {
        tail->next = new Node<T>(element);
        tail = tail->next;
    }

    size++;
}

template<typename T>
T LinkedList<T>::getFirst() const
{
    if (size == 0)
        throw std::runtime_error("Index out of range");

    return head->element;
}

template<typename T>
T LinkedList<T>::getLast() const
{
    if (size == 0)
        throw std::runtime_error("Index out of range");

    return tail->element;
}

template<typename T>
T LinkedList<T>::removeFirst()
{
    if (size == 0)
        throw std::runtime_error("No elements in the list");

    Node<T>* temp = head;
    head = head->next;
    if (head == NULL)
        tail = NULL;
    size--;
    T element = temp->element;
    delete temp;
    return element;
}

template<typename T>
T LinkedList<T>::removeLast()
{
    if (size == 0)
        throw std::runtime_error("No elements in the list");
    if (size == 1)
    {
        Node<T>* temp = head;
        head = tail = NULL;
        size = 0;
        T element = temp->element;
        delete temp;
        return element;
    }

    Node<T>* current = head;
    for (int i = 0; i < size - 2; i++)
        current = current->next;

    Node<T>* temp = tail;
    tail = current;
    tail->next = NULL;
    size--;
    T element = temp->element;
    delete temp;
    return element;
}

template<typename T>
void LinkedList<T>::add(T element)
{
    addLast(element);
}

template<typename T>
void LinkedList<T>::add(int index, T element)
{
    if (index == 0)
        addFirst(element);
    else if (index >= size)
        addLast(element);
    else
    {
        Node<T>* current = head;
        for (int i = 1; i < index; i++)
            current = current->next;
        Node<T>* temp = current->next;
        current->next = new Node<T>(element);
        current->next->next = temp;
        size++;
    }
}

template<typename T>
void LinkedList<T>::clear()
{
    while (head != NULL)
    {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    tail = NULL;
    size = 0;
}

template<typename T>
bool LinkedList<T>::contains(T element) const
{
    return indexOf(element) != -1;
}

template<typename T>
T LinkedList<T>::get(int index) const
{
    return getNode(index)->element;
}

template<typename T>
int LinkedList<T>::indexOf(T element) const
{
    Node<T>* current = head;
    for (int i = 0; i < size; i++)
    {
        if (current->element == element)
            return i;
        current = current->next;
    }

    return -1;
}

template<typename T>
bool LinkedList<T>::isEmpty() const
{
    return head == NULL;
}

template<typename T>
int LinkedList<T>::lastIndexOf(T element) const
{
    int index = -1;
    Node<T>* current = head;
    for (int i = 0; i < size; i++)
    {
        if (current->element == element)
            index = i;
        current = current->next;
    }

    return index;
}

template<typename T>
void LinkedList<T>::remove(T element)
{
    if (size == 0)
        return;

    if (head->element == element)
    {
        removeFirst();
        return;
    }

    Node<T>* previous = head;
    Node<T>* current = head->next;
    while (current != NULL)
    {
        if (current->element == element)
        {
            previous->next = current->next;
            if (current == tail)
                tail = previous;
            delete current;
            size--;
            return;
        }

        previous = current;
        current = current->next;
    }
}

template<typename T>
int LinkedList<T>::getSize() const
{
    return size;
}

template<typename T>
T LinkedList<T>::removeAt(int index)
{
    if (index < 0 || index >= size)
        throw std::runtime_error("Index out of range");
    if (index == 0)
        return removeFirst();
    if (index == size - 1)
        return removeLast();

    Node<T>* previous = head;
    for (int i = 1; i < index; i++)
        previous = previous->next;

    Node<T>* current = previous->next;
    previous->next = current->next;
    size--;
    T element = current->element;
    delete current;
    return element;
}

template<typename T>
T LinkedList<T>::set(int index, T element)
{
    Node<T>* current = getNode(index);
    T oldElement = current->element;
    current->element = element;
    return oldElement;
}

template<typename T>
void LinkedList<T>::reverse()
{
    Node<T>* previous = NULL;
    Node<T>* current = head;
    tail = head;

    while (current != NULL)
    {
        Node<T>* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    head = previous;
}

template<typename T>
void LinkedList<T>::sort()
{
    if (size < 2)
        return;

    bool changed = true;
    while (changed)
    {
        changed = false;
        Node<T>* current = head;
        while (current != NULL && current->next != NULL)
        {
            if (current->element > current->next->element)
            {
                T temp = current->element;
                current->element = current->next->element;
                current->next->element = temp;
                changed = true;
            }
            current = current->next;
        }
    }
}

template<typename T>
void LinkedList<T>::addAll(LinkedList<T>& otherList)
{
    for (Iterator<T> iterator = otherList.begin(); iterator != otherList.end(); iterator++)
        add(*iterator);
}

template<typename T>
void LinkedList<T>::removeAll(LinkedList<T>& otherList)
{
    for (Iterator<T> iterator = otherList.begin(); iterator != otherList.end(); iterator++)
    {
        while (contains(*iterator))
            remove(*iterator);
    }
}

template<typename T>
void LinkedList<T>::retainAll(LinkedList<T>& otherList)
{
    Node<T>* current = head;
    while (current != NULL)
    {
        Node<T>* nextNode = current->next;
        if (!otherList.contains(current->element))
            remove(current->element);
        current = nextNode;
    }
}

template<typename T>
LinkedList<T> LinkedList<T>::operator+(LinkedList<T>& otherList) const
{
    LinkedList<T> result(*this);
    result.addAll(otherList);
    return result;
}

template<typename T>
LinkedList<T> LinkedList<T>::operator-(LinkedList<T>& otherList) const
{
    LinkedList<T> result(*this);
    result.removeAll(otherList);
    return result;
}

template<typename T>
LinkedList<T> LinkedList<T>::operator^(LinkedList<T>& otherList) const
{
    LinkedList<T> result(*this);
    result.retainAll(otherList);
    return result;
}

template<typename T>
T& LinkedList<T>::operator[](int index)
{
    return getNode(index)->element;
}

template<typename T>
Node<T>* LinkedList<T>::getNode(int index) const
{
    if (index < 0 || index >= size)
        throw std::runtime_error("Index out of range");

    Node<T>* current = head;
    for (int i = 0; i < index; i++)
        current = current->next;

    return current;
}

#endif
