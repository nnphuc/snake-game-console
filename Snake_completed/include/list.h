#ifndef LIST_H
#define LIST_H

#include "ListNode.h"
#include "utility.h"

template <class T>
class List
{
    public:
        List();
        List(const List<T> &other);
        List<T> &operator=(const List<T> &other);
        const List<T> &operator=(const List<T> &other) const;
        void clear();
        virtual ~List();

        ListNode<T>* pushFront(T data);
        ListNode<T>* pushBack(T data);
        void popBack();
        void popFront();
        T &front();
        const T& front() const;
        T &back();
        const T& back() const;
        bool isEmpty() const;

        ListNode<T> *head();
        ListNode<T> *tail();
        const ListNode<T>* head() const;
        const ListNode<T>* tail() const;
        int size() const;

    protected:

    private:
        int m_size;
        ListNode<T> *m_head;
        ListNode<T> *m_tail;
};

template <class T>
void List<T>::clear()
{
    while(!isEmpty()){
        popBack();
    }
}

template <class T>
const ListNode<T> *List<T>::head() const
{
    return m_head;
}

template <class T>
List<T>::List(const List<T> &other)
{
    if(this==&other){
        return;
    }
    m_size=0;
    m_head=m_tail=NULL;
    ListNode<T> *p=other.head();
    while(p!=NULL){
        pushBack(p->data());
        p=p->next();
    }
}

template <class T>
List<T> &List<T>::operator=(const List<T> &other)
{
    if(this==&other){
        return *this;
    }
    m_size=0;
    m_head=m_tail=NULL;
    ListNode<T> *p=other.head();
    while(p!=NULL){
        pushBack(p->data());
        p=p->next();
    }
    return *this;
}

template <class T>
const List<T> &List<T>::operator=(const List<T> &other) const
{
    if(this==&other){
        return *this;
    }
    m_size=0;
    m_head=m_tail=NULL;
    const ListNode<T> *p=other.head();
    while(p!=NULL){
        pushBack(p->data());
        p=p->next();
    }
    return *this;
}

template <class T>
int List<T>::size() const{
    return m_size;
}

template <class T>
void List<T>::popFront()
{
    if(isEmpty()){
        return;
    }
    m_size--;
    if(m_size==0){
        delete m_head;
        m_head=m_tail=NULL;
        return;
    }
    ListNode<T> * head=m_head;
    m_head=m_head->next();
    m_head->setPrev(NULL);
    delete head;

}

template <class T>
void List<T>::popBack()
{
    if(isEmpty()){
        return;
    }
    m_size--;
    if(m_size==0){
        delete m_head;
        m_head=m_tail=NULL;
        return;
    }
    ListNode<T>* tail=m_tail;
    m_tail=m_tail->prev();
    m_tail->setNext(NULL);
    delete tail;

}

template <class T>
ListNode<T> *List<T>::head()
{
    return m_head;
}

template <class T>
ListNode<T> *List<T>::tail()
{
    return m_tail;
}

template <class T>
ListNode<T>* List<T>::pushBack(T data)
{
    m_size++;
    ListNode<T> * node=new ListNode<T>(data);
    if(isEmpty()){
        m_head=m_tail=node;
    }else{
        m_tail->setNext(node);
        node->setPrev(m_tail);
        m_tail=node;
    }
    return node;
}

template <class T>
ListNode<T> *List<T>::pushFront(T data)
{
    m_size++;
    ListNode<T> *node=new ListNode<T>(data);
    if(isEmpty()){
        m_head=m_tail=node;
    }else{
        m_head->setPrev(node);
        node->setNext(m_head);
        m_head=node;
    }
    return node;
}
template <class T>
bool List<T>::isEmpty() const
{
    return m_head==NULL;
}
template <class T>
T &List<T>::front()
{
    if(isEmpty()){
        //std::cout<<"#List"<<" "<<typeid(T).name()<<std::endl;
        throw "empty list";
    }
    return m_head->data();
}

template <class T>
const T& List<T>::front() const
{
    if(isEmpty()){
        //std::cout<<"#List"<<" "<<typeid(T).name()<<std::endl;
        throw "empty list";
    }
    return m_head->data();
}

template <class T>
T &List<T>::back()
{
    if(isEmpty()){
        throw "empty list";
    }
    return m_tail->data();
}

template <class T>
const T& List<T>::back() const
{
    if(isEmpty()){
        throw "empty list";
    }
    return m_tail->data();
}

template <class T>
List<T>::List()
{
    m_size=0;
    m_head=m_tail=NULL;
}

template <class T>
List<T>::~List()
{
    ListNode<T>* cur=m_head;
    ListNode<T>* toDelete;
    while(cur!=NULL){
        toDelete=cur;
        cur=cur->next();
        delete toDelete;
    }
}

#endif // LIST_H
