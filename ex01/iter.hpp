#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>
#include <type_traits>

template <typename T>
void iter(T *arr, size_t len, void (*func)(T &))
{
    for (size_t i = 0; i < len; i++)
        func(arr[i]);
}

template <typename T>
void iter(const T *arr, size_t len, void (*func)(const T &))
{
    for (size_t i = 0; i < len; ++i)
        func(arr[i]);
}

template <typename T>
void printElement(const T &element)
{
    std::cout << "element: " << element << std::endl;
}

template <typename T>
void doubleElement(T &element)
{
    element *= 2;
}

#endif
