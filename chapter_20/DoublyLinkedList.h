#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <stdexcept>

template<typename T>
class DoublyNode
{
public:
    T element;
    DoublyNode<T>* previous;
    DoublyNode<T>* next;

    DoublyNode()
    {
        previous = NULL;
        next = NULL;
    }

    DoublyNode(T element)
    {
        this->element = element;
        previous = NULL;
        next = NULL;
    }
};

template<typename T>
class DoublyIterator
{
public:
    DoublyIterator(DoublyNode<T>* p)
    {
        current = p;
    }

    DoublyIterator operator++()
    {
        current = current->next;
        return *this;
    }

    DoublyIterator operator++(int)
    {
        DoublyIterator temp(current);
        current = current->next;
        return temp;
    }

    DoublyIterator operator--()
    {
        current = current->previous;
        return *this;
    }

    DoublyIterator operator--(int)
    {
        DoublyIterator temp(current);
        current = current->previous;
        return temp;
    }

    T& operator*()
    {
        return current->element;
    }

    bool operator==(const DoublyIterator<T>& iterator) const
    {
        return current == iterator.current;
    }

    bool operator!=(const DoublyIterator<T>& iterator) const
    {
        return current != iterator.current;
    }

private:
    DoublyNode<T>* current;
};

template<typename T>
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList<T>& list);
    ~DoublyLinkedList();
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& list);

    void addFirst(T element);
    void addLast(T element);
    void add(T element);
    void add(int index, T element);
    T removeFirst();
    T removeLast();
    T removeAt(int index);
    T get(int index) const;
    int getSize() const;
    void clear();

    DoublyIterator<T> begin() const
    {
        return DoublyIterator<T>(head);
    }

    DoublyIterator<T> end() const
    {
        return DoublyIterator<T>(NULL);
    }

private:
    DoublyNode<T>* head;
    DoublyNode<T>* tail;
    int size;
    DoublyNode<T>* getNode(int index) const;
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = tail = NULL;
    size = 0;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& list)
{
    head = tail = NULL;
    size = 0;

    DoublyNode<T>* current = list.head;
    while (current != NULL)
    {
        add(current->element);
        current = current->next;
    }
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    clear();
}

template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& list)
{
    if (this != &list)
    {
        clear();
        DoublyNode<T>* current = list.head;
        while (current != NULL)
        {
            add(current->element);
            current = current->next;
        }
    }
    return *this;
}

template<typename T>
void DoublyLinkedList<T>::addFirst(T element)
{
    DoublyNode<T>* newNode = new DoublyNode<T>(element);
    newNode->next = head;
    if (head != NULL)
        head->previous = newNode;
    head = newNode;
    if (tail == NULL)
        tail = head;
    size++;
}

template<typename T>
void DoublyLinkedList<T>::addLast(T element)
{
    DoublyNode<T>* newNode = new DoublyNode<T>(element);
    newNode->previous = tail;
    if (tail != NULL)
        tail->next = newNode;
    tail = newNode;
    if (head == NULL)
        head = tail;
    size++;
}

template<typename T>
void DoublyLinkedList<T>::add(T element)
{
    addLast(element);
}

template<typename T>
void DoublyLinkedList<T>::add(int index, T element)
{
    if (index <= 0)
        addFirst(element);
    else if (index >= size)
        addLast(element);
    else
    {
        DoublyNode<T>* current = getNode(index);
        DoublyNode<T>* newNode = new DoublyNode<T>(element);
        newNode->previous = current->previous;
        newNode->next = current;
        current->previous->next = newNode;
        current->previous = newNode;
        size++;
    }
}

template<typename T>
T DoublyLinkedList<T>::removeFirst()
{
    if (size == 0)
        throw std::runtime_error("No elements in the list");

    DoublyNode<T>* temp = head;
    head = head->next;
    if (head != NULL)
        head->previous = NULL;
    else
        tail = NULL;
    size--;
    T element = temp->element;
    delete temp;
    return element;
}

template<typename T>
T DoublyLinkedList<T>::removeLast()
{
    if (size == 0)
        throw std::runtime_error("No elements in the list");

    DoublyNode<T>* temp = tail;
    tail = tail->previous;
    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL;
    size--;
    T element = temp->element;
    delete temp;
    return element;
}

template<typename T>
T DoublyLinkedList<T>::removeAt(int index)
{
    if (index < 0 || index >= size)
        throw std::runtime_error("Index out of range");
    if (index == 0)
        return removeFirst();
    if (index == size - 1)
        return removeLast();

    DoublyNode<T>* current = getNode(index);
    current->previous->next = current->next;
    current->next->previous = current->previous;
    size--;
    T element = current->element;
    delete current;
    return element;
}

template<typename T>
T DoublyLinkedList<T>::get(int index) const
{
    return getNode(index)->element;
}

template<typename T>
int DoublyLinkedList<T>::getSize() const
{
    return size;
}

template<typename T>
void DoublyLinkedList<T>::clear()
{
    while (head != NULL)
    {
        DoublyNode<T>* temp = head;
        head = head->next;
        delete temp;
    }

    tail = NULL;
    size = 0;
}

template<typename T>
DoublyNode<T>* DoublyLinkedList<T>::getNode(int index) const
{
    if (index < 0 || index >= size)
        throw std::runtime_error("Index out of range");

    if (index < size / 2)
    {
        DoublyNode<T>* current = head;
        for (int i = 0; i < index; i++)
            current = current->next;
        return current;
    }

    DoublyNode<T>* current = tail;
    for (int i = size - 1; i > index; i--)
        current = current->previous;
    return current;
}

#endif
