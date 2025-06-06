#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
private:
    T *data;
    size_t len;

public:
    ~Array();
    Array();
    Array(unsigned int n);
    Array(const Array &src);
    Array &operator=(const Array &src);
    T &operator[](size_t index);
    void copyFrom(const Array &src);
    void forEach(void (*func)(T &));
    size_t size() const;
};

template <typename T>
Array<T>::~Array()
{
    if (this->data)
        delete[] this->data;
}

template <typename T>
Array<T>::Array() : data(0), len(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]), len(n)
{
}

template <typename T>
Array<T>::Array(const Array<T> &src)
{
    this->copyFrom(src);
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &src)
{
    if (this == &src)
        return *this;
    if (this->data)
        delete[] this->data;
    this->copyFrom(src);
    return *this;
}

template <typename T>
T &Array<T>::operator[](size_t index)
{
    if (index >= this->len)
        throw std::runtime_error("Bad index access");
    return this->data[index];
}

template <typename T>
void Array<T>::copyFrom(const Array &src)
{
    this->len = src.len;
    this->data = new T[this->len];
    for (size_t i = 0; i < this->len; i++)
        this->data[i] = src.data[i];
}

template <typename T>
void Array<T>::forEach(void (*func)(T &))
{
    for (size_t i = 0; i < this->len; i++)
        func(this->data[i]);
}

template <typename T>
size_t Array<T>::size() const
{
    return this->len;
}

#endif
