#include "data_structures.h"

// This file exists to help with compilation
// Since our library is header-only, we just need to ensure the headers compile properly

// 显式实例化一些常用类型以检查编译
// Explicit instantiation of common types to check compilation

template class DynamicArray<int>;
template class DynamicArray<std::string>;

template class LinkedList<int>;
template class LinkedList<std::string>;

template class Stack<int>;
template class Stack<std::string>;

template class Queue<int>;
template class Queue<std::string>;

template class BinarySearchTree<int>;
template class BinarySearchTree<std::string>;

template class HashTable<std::string, int>;
template class HashTable<int, std::string>;