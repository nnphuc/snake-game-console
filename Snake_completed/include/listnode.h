#ifndef LISTNODE_H
#define LISTNODE_H

#include "utility.h"

template <class T>
class ListNode
{
    public:
        ListNode(const ListNode<T> &other);
        ListNode();
        ListNode(T data,ListNode<T>* prev=NULL,ListNode<T>* next=NULL);

        virtual ~ListNode();
        void setNext(ListNode<T>* next);
        void setPrev(ListNode<T>* prev);

        ListNode<T>* next();
        ListNode<T>* prev();
        const ListNode<T> *next() const;
        const ListNode<T> * prev() const;

        bool hasNext() const;
        bool hasPrev() const;

        T & data();
        const T& data() const;

    protected:

    private:
        T m_data;
        ListNode<T> *m_prev;
        ListNode<T> *m_next;
};

template <class T>
const ListNode<T>* ListNode<T>::next() const
{
    return m_next;
}

template <class T>
const ListNode<T>* ListNode<T>::prev() const
{
    return m_prev;
}

template <class T>
T &ListNode<T>::data()
{
    return m_data;
}

template <class T>
const T &ListNode<T>::data() const
{
    return m_data;
}

template <class T>
ListNode<T>::ListNode()
{
    m_data=T();
    m_prev=m_next=NULL;
}

template <class T>
ListNode<T>::ListNode(T data,ListNode<T>* prev,ListNode<T>* next)
{
    m_data=data;
    m_prev=prev;
    m_next=next;
}

template <class T>
ListNode<T>::~ListNode()
{
    //dtor
}

template <class T>
void ListNode<T>::setNext(ListNode<T>* next)
{
    m_next=next;
}

template <class T>
void ListNode<T>::setPrev(ListNode<T>* prev)
{
    m_prev=prev;
}

template <class T>
ListNode<T>* ListNode<T>::next()
{
    return m_next;
}

template <class T>
ListNode<T>* ListNode<T>::prev()
{
    return m_prev;
}

template <class T>
bool ListNode<T>::hasNext() const
{
    return m_next!=NULL;
}

template <class T>
bool ListNode<T>::hasPrev() const
{
    return m_prev!=NULL;
}

#endif // LISTNODE_H
