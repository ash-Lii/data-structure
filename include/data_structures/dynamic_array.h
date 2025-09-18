#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

/**
 * @brief 动态数组类 - Dynamic Array Class
 * 实现基本的动态数组操作，包括插入、删除、查找等
 */
template<typename T>
class DynamicArray {
private:
    std::vector<T> data;

public:
    DynamicArray() = default;
    explicit DynamicArray(size_t initial_capacity);
    
    // 基本操作 - Basic Operations
    void push_back(const T& value);
    void pop_back();
    T& at(size_t index);
    const T& at(size_t index) const;
    
    // 插入和删除 - Insert and Delete
    void insert(size_t index, const T& value);
    void erase(size_t index);
    
    // 查找 - Search
    int find(const T& value) const;
    
    // 属性 - Properties
    size_t size() const { return data.size(); }
    bool empty() const { return data.empty(); }
    
    // 打印 - Print
    void print() const;
    
    // 迭代器支持 - Iterator support
    typename std::vector<T>::iterator begin() { return data.begin(); }
    typename std::vector<T>::iterator end() { return data.end(); }
    typename std::vector<T>::const_iterator begin() const { return data.begin(); }
    typename std::vector<T>::const_iterator end() const { return data.end(); }
};

// 模板实现必须在头文件中
template<typename T>
DynamicArray<T>::DynamicArray(size_t initial_capacity) {
    data.reserve(initial_capacity);
}

template<typename T>
void DynamicArray<T>::push_back(const T& value) {
    data.push_back(value);
}

template<typename T>
void DynamicArray<T>::pop_back() {
    if (empty()) {
        throw std::runtime_error("Cannot pop from empty array");
    }
    data.pop_back();
}

template<typename T>
T& DynamicArray<T>::at(size_t index) {
    if (index >= size()) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
const T& DynamicArray<T>::at(size_t index) const {
    if (index >= size()) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
void DynamicArray<T>::insert(size_t index, const T& value) {
    if (index > size()) {
        throw std::out_of_range("Index out of range");
    }
    data.insert(data.begin() + index, value);
}

template<typename T>
void DynamicArray<T>::erase(size_t index) {
    if (index >= size()) {
        throw std::out_of_range("Index out of range");
    }
    data.erase(data.begin() + index);
}

template<typename T>
int DynamicArray<T>::find(const T& value) const {
    for (size_t i = 0; i < size(); ++i) {
        if (data[i] == value) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

template<typename T>
void DynamicArray<T>::print() const {
    std::cout << "[";
    for (size_t i = 0; i < size(); ++i) {
        std::cout << data[i];
        if (i < size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}