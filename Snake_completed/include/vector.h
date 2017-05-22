#ifndef VECTOR_H
#define VECTOR_H


#include "utility.h"

template <class T>
class Vector{
public:
    Vector();
    Vector(const Vector<T> &other);
    Vector<T> &operator=(const Vector<T>& other);
    const Vector<T> &operator=(const Vector<T> &other) const;

    Vector(int size);
    Vector(T *data,int size);
    Vector(int size,T data);

    bool isEmpty() const;
    void push(T data);
    void pop();
    void resize(int size);
    void resize(int size,T data);
    const T& operator[](int index) const;
    T& operator[](int index);
    int size() const;

    T& front();
    const T& front() const;

    T& back();
    const T& back() const;

    virtual ~Vector();


private:
    T * m_data;
    int m_size;
    int m_capacity;
    static const int DEFAULT_CAPACITY=2;

};

template <class T>
Vector<T>::Vector(int size,T data)
{
    m_size=0;
    m_capacity=DEFAULT_CAPACITY;
    m_data=NULL;
    resize(size,data);
}
template <class T>
Vector<T>::Vector(int size)
{
    m_size=0;
    m_capacity=DEFAULT_CAPACITY;
    m_data=NULL;
    resize(size);
    for(int i=0;i<size;i++){
        m_data[i]=T();
    }
}


template <class T>
bool Vector<T>::isEmpty() const
{
    return m_size<=0;
}

template <class T>
void Vector<T>::pop()
{
    if(isEmpty()){
        std::cout<<typeid(T).name()<<std::endl;
        throw "empty Vector";
    }
    resize(m_size-1);
}

template <class T>
T& Vector<T>::front()
{
    return this->operator[](0);
}

template <class T>
const T& Vector<T>::front() const
{
    return this->operator[](0);
}

template <class T>
T& Vector<T>::back()
{
    return this->operator[](-1);
}

template <class T>
const T& Vector<T>::back() const
{
    return this->operator[](-1);
}

template <class T>
int Vector<T>::size() const
{
    return m_size;
}


template <class T>
const T& Vector<T>::operator[](int index) const
{
    if(m_size==0){
        std::cout<<typeid(T).name()<<std::endl;
        throw "empty Vector";
    }
    int i=(index%m_size+m_size)%m_size;
    return m_data[i];
}

template <class T>
T& Vector<T>::operator[](int index)
{
    if(m_size==0){
        std::cout<<typeid(T).name()<<std::endl;
        throw "empty Vector";
    }
    int i=(index%m_size+m_size)%m_size;
    return m_data[i];
}

template <class T>
void Vector<T>::resize(int size)
{
    if(size==m_size) return;

    if(size>m_size){
        while(m_capacity<=size){
            m_capacity*=2;
        }
    }else{
        while(m_capacity>DEFAULT_CAPACITY && m_capacity>size*2){
            m_capacity/=2;
        }
    }
    T * old_data=m_data;
    m_data=new T[m_capacity];
    for(int i=0;i<min2(size,m_size);i++){
        m_data[i]=old_data[i];
    }
    m_size=size;
    delete [] old_data;
}

template <class T>
void Vector<T>::resize(int size,T data)
{
    int old_size=m_size;
    resize(size);
    for(int i=old_size;i<size;i++){
        m_data[i]=data;
    }
}

template <class T>
void Vector<T>::push(T data)
{
    resize(m_size+1,data);
}


template <class T>
Vector<T>::Vector()
{
    m_size=0;
    m_capacity=DEFAULT_CAPACITY;
    m_data=new T[m_capacity];
}

template <class T>
Vector<T>::Vector(const Vector<T> &other)
{
    if(this==&other){
        return;
    }
    resize(other.size());
    for(int i=0;i<m_size;i++){
        m_data[i]=other.m_data[i];
    }
}

template <class T>
Vector<T> &Vector<T>::operator=(const Vector<T> &other)
{
    if(this==&other){
        return *this;
    }
    resize(other.size());
    for(int i=0;i<m_size;i++){
        m_data[i]=other.m_data[i];
    }
    return *this;
}

template <class T>
const Vector<T> &Vector<T>::operator=(const Vector<T> &other) const
{
    if(this==&other){
        return *this;
    }
    resize(other.size());
    for(int i=0;i<m_size;i++){
        m_data[i]=other.m_data[i];
    }
    return *this;
}


template <class T>
Vector<T>::~Vector()
{
    delete [] m_data;
}

#endif // VECTOR_H
