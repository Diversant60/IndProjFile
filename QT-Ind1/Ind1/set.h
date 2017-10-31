#ifndef SET_H define SET_H

#include <iostream>

#include "dllist.h"

template <class T>
class set: protected dllist<T>
{
    public:

    typedef typename dllist<T>::iterator iterator;

    set();
    set(const set<T>& other);
    ~set();

    set<T>& operator = (const set<T>& other);

    void insert(const T& value);

    bool erase(const T& value);

    bool empty() const;

    iterator find(const T& value);

    void operator |= (const T& value);
    bool operator /= (const T& value);
    set<T>& operator || (const set<T>& other);
    set<T>& operator && (const set<T>& other);

    bool operator == (const set<T>& other) const;
    bool operator != (const set<T>& other) const;

    template <class T1>
    friend std::ostream& operator<< (std::ostream& os, const set<T1>& out);
    template <class T1>
    friend std::istream& operator>> (std::istream& is, set<T1>& in);

    static set<T> get_set(const int count, std::istream &source);

    iterator begin();
    iterator end();
};

template <class T>
set<T>::set()
    : dllist<T>()
{
}

template <class T>
set<T>::set(const set<T>& other)
    : dllist<T>()
{
    for(node<T>* pnode = other.head; pnode != NULL; pnode = pnode->next)
        this->push_back(pnode->value);
}

template <class T>
set<T>::~set()
{

    while(dllist<T>::head != NULL)
    {
        node<T>* pnode = dllist<T>::head;
        dllist<T>::head = dllist<T>::head->next;
        delete pnode;
    }
}

template <class T>
set<T>& set<T>::operator = (const set<T>& other)
{
    dllist<T>::head = dllist<T>::tail = NULL;

    for(node<T>* pnode = other.head; pnode != NULL; pnode = pnode->next)
        this->push_back(pnode->value);

    return *this;
}

template <class T>
void set<T>::insert(const T& value)
{
    node<T>* pnode = dllist<T>::head;

    while(true)
    {
        if(pnode == NULL)
        {
            this->push_back(value);
            break;
        }

        else if(pnode->value > value)
        {
            node<T>* newnode = new node<T>(value, pnode, pnode->prev);

            node<T>* prev = pnode->prev;

            if(prev != NULL)
                prev->next = newnode;
            else
                dllist<T>::head = newnode;

            pnode->prev = newnode;

            break;
        }

        else if(pnode->value == value)
            break;

        else
            pnode = pnode->next;
    }
}

template <class T>
bool set<T>:: erase(const T& value)
{
    if(dllist<T>::head)
    {
        if(dllist<T>::head->next==NULL)
        {
            if(value==dllist<T>::head->value)
            {
                delete dllist<T>::head;
                dllist<T>::head=dllist<T>::tail=NULL;
                return true;
            }
            return false;
        }

        node<T>* ptr = dllist<T>::head;

        if(value==dllist<T>::head->value)
        {
            dllist<T>::head=dllist<T>::head->next;
            delete ptr;
            return true;
        }
        else while(ptr)
        {
            if(value==ptr->value)
            {
                node<T>* ptr_prev = ptr->prev;
                node<T>* ptr_next = ptr->next;

                if(ptr_prev)
                    ptr_prev->next = ptr_next;
                if(ptr_next)
                    ptr_next->prev = ptr_prev;

                delete ptr;
                if(dllist<T>::head==NULL)
                    dllist<T>::head=dllist<T>::tail=NULL;

                return true;
            }
            ptr = ptr->next;
        }
    }
    return false;
}

template <class T>
bool set<T>::empty() const
{
    return dllist<T>::empty();
}

template <class T>
typename set<T>::iterator set<T>::find(const T& value)
{
    node<T>* ptr = dllist<T>::head;

    while(ptr)
    {
        if(value==ptr->value)
        {
            return iterator(ptr);
        }
        ptr = ptr->next;
    }
    return iterator(NULL);
}

template <class T>
void set<T>::operator |= (const T& value)
{
    this->insert(value);
}

template <class T>
bool set<T>::operator /= (const T& value)
{
    return this->erase(value);
}

template <class T>
set<T>& set<T>::operator || (const set<T>& other)
{
    for(node<T>* pnode = other.head; pnode != NULL; pnode = pnode->next)
        this->insert(pnode->value);

    return *this;
}

template <class T>
set<T>& set<T>::operator && (const set<T>& other)
{
    set<T> res;

    for(node<T>* pnode1 = other.head; pnode1 != NULL; pnode1 = pnode1->next)
        for(node<T>* pnode2 = this->head; pnode2 != NULL; pnode2 = pnode2->next)
            if(pnode1->value==pnode2->value)
                res.insert(pnode1->value);

    dllist<T>::head = dllist<T>::tail = NULL;

    for(node<T>* pnode = res.head; pnode != NULL; pnode = pnode->next)
        this->insert(pnode->value);

    return *this;
}

template <class T>
bool set<T>::operator == (const set<T>& other) const
{
    node<T>* pnode1 = other.head;
    node<T>* pnode2 = this->head;

    while(pnode1 && pnode2)
    {
        if(pnode1->value!=pnode2->value)
            return false;
        pnode1 = pnode1->next;
        pnode2 = pnode2->next;
    }
    if( !(pnode1 || pnode2))
    return true;
    return false;
}

template <class T>
bool set<T>::operator != (const set<T>& other) const
{
    return !(*this==other);
}

template <class T1>
std::ostream& operator<<(std::ostream& os, const set<T1>& out)
{
    node<T1>* pnode = out.head;

    while (pnode->next)
    {
        os << pnode->value << " ";
        pnode = pnode->next;
    }
    os << pnode->value << std::endl;
    return os;
}

template <typename T>
set<T>  set<T>::get_set(const int count, std::istream &source)
{
    set<T> new_set;
    for (int i = 0; i < count; ++i) {
        T t;
        if (source >> t){
            new_set.insert(t);
        }
    }
    return  new_set;
}


template <class T1>
std::istream& operator>>(std::istream& is, set<T1>& in)
{
    std::cout << "Enter the number of entries:" << std::endl;
    int k;
    std::cin >> k;

    in = set<T1>::get_set(k, is);
        return is;
}

template <class T>
typename set<T>::iterator set<T>::begin()
{
    return dllist<T>::begin();
}

template <class T>
typename set<T>::iterator set<T>::end()
{
    return dllist<T>::end();
}

#endif
