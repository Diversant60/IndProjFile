#ifndef DLLIST_H
#define DLLIST_H

#include <cstdlib>
#include <stdexcept>
#include <cstddef>

template <class T>
class node
{
public:
    T value;
    node* next;
    node* prev;
    node(const T&, node<T>*, node<T>*);
};

template <class T>
node<T>::node(const T& val, node<T>* n, node<T>* p)
    : value(val), next(n), prev(p)
{
}

template <class T>
class dllist;

template <class T>
class dllist_iterator
{
private:
    friend class dllist<T>;

    void assert_is_valid() const;

    node<T>* pnode;

public:
     dllist_iterator(node<T>*);

    typedef ptrdiff_t difference_type;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef size_t size_type;
    typedef std::forward_iterator_tag iterator_category;

    dllist_iterator();
    dllist_iterator(const dllist_iterator<T>&);

    dllist_iterator& operator = (const dllist_iterator<T>&);

    bool operator == (const dllist_iterator<T>&) const;
    bool operator != (const dllist_iterator<T>&) const;

    T& operator * ();
    T* operator -> ();

    dllist_iterator<T>& operator ++ ();
    dllist_iterator<T> operator ++ (int);

    bool is_valid() const;

};

template <class T>
dllist_iterator<T>::dllist_iterator(node<T>* p)
    : pnode(p)
{
}

template <class T>
dllist_iterator<T>::dllist_iterator()
    : pnode(NULL)
{
}

template <class T>
dllist_iterator<T>::dllist_iterator(const dllist_iterator<T>& rhs)
    : pnode(rhs.pnode)
{
}

template <class T>
dllist_iterator<T>& dllist_iterator<T>::operator = (const dllist_iterator<T>& rhs)
{
    pnode = rhs.pnode;
}

template <class T>
bool dllist_iterator<T>::operator == (const dllist_iterator<T>& rhs) const
{
    return pnode == rhs.pnode;
}

template <class T>
bool dllist_iterator<T>::operator != (const dllist_iterator<T>& rhs) const
{
    return pnode != rhs.pnode;
}

template <class T>
T& dllist_iterator<T>::operator * ()
{
    assert_is_valid();
    return pnode->value;
}

template <class T>
T* dllist_iterator<T>::operator -> ()
{
    assert_is_valid();

    return &(pnode->value);
}

template <class T>
dllist_iterator<T>& dllist_iterator<T>::operator ++ ()
{
    assert_is_valid();

    pnode = pnode->next;
    return *this;
}

template <class T>
dllist_iterator<T> dllist_iterator<T>::operator ++ (int)
{
    assert_is_valid();

    dllist_iterator<T> tmp = *this;

    ++(*this);

    return tmp;
}

template <class T>
void dllist_iterator<T>::assert_is_valid() const
{
    if(!is_valid())
        throw std::runtime_error("Invalid iterator");
}

template <class T>
bool dllist_iterator<T>::is_valid() const
{
    return pnode != NULL;
}

template <class T>
class dllist
{
protected:
    node<T>* head;
    node<T>* tail;

public:
    typedef dllist_iterator<T> iterator;

    dllist();
    dllist(const dllist<T>&);

    void push_back(const T&);
    void push_front(const T&);

    T pop_front();
    T pop_back();

    bool empty () const;

    dllist<T>& operator = (const dllist<T>&);

    iterator begin();
    iterator end();

    ~dllist();
};

template <class T>
dllist<T>::dllist()
    : head(NULL), tail(NULL)
{
}

template <class T>
dllist<T>::dllist(const dllist<T>& rhs)
    : head(NULL), tail(NULL)
{
    for(node<T>* pnode = rhs.head;
        pnode != NULL; pnode = pnode->next)
        push_back(pnode->value);
}

template <class T>
void dllist<T>::push_back(const T& value)
{
    node<T>* pnode = new node<T>(value, NULL, tail);

    if(tail != NULL)
        tail->next = pnode;
    else
        head = pnode;

    tail = pnode;
}

template <class T>
void dllist<T>::push_front(const T& value)
{
    node<T>* pnode = new node<T>(value, head, NULL);

    if(head != NULL)
        head->prev = pnode;
    else
        tail = pnode;

    head = pnode;
}

template <class T>
T dllist<T>::pop_back()
{
    if(tail == NULL)
        throw std::runtime_error("Empty list");

    node<T>* pnode = tail;
    T value = pnode->value;

    tail = tail->prev;

    delete pnode;

    if(tail == NULL)
        head = NULL;
    else
        tail->next = NULL;

    return value;
}

template <class T>
T dllist<T>::pop_front()
{
    if(head == NULL)
        throw std::runtime_error("Empty list");

    node<T>* pnode = head;
    T value = pnode->value;

    head = head->next;

    delete pnode;

    if(head == NULL)
        tail == NULL;
    else
        head->prev = NULL;

    return value;
}

template <class T>
bool dllist<T>::empty() const
{
    return head == NULL;
}


template <class T>
dllist<T>& dllist<T>::operator = (const dllist<T>& rhs)
{
    head = tail = NULL;

    for(node<T>* pnode = rhs.head;
        pnode != NULL; pnode = pnode->next)
        push_back(pnode->value);

    return *this;
}

template <class T>
dllist<T>::~dllist()
{
    while(head != NULL)
    {
        node<T>* pnode = head;
        head = head->next;
        delete pnode;
    }
}

template <class T>
typename dllist<T>::iterator dllist<T>::begin()
{
    return iterator(head);
}

template <class T>
typename dllist<T>::iterator dllist<T>::end()
{
    return iterator();
}

#endif
