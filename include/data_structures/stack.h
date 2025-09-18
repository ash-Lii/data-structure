#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

/**
 * @brief 栈类 - Stack Class
 * 基于动态数组实现的栈（LIFO - Last In First Out）
 */
template<typename T>
class Stack {
private:
    std::vector<T> data;

public:
    Stack() = default;
    
    // 栈操作 - Stack Operations
    void push(const T& value);
    void pop();
    T& top();
    const T& top() const;
    
    // 属性 - Properties
    size_t size() const { return data.size(); }
    bool empty() const { return data.empty(); }
    
    // 打印 - Print
    void print() const;
};

template<typename T>
void Stack<T>::push(const T& value) {
    data.push_back(value);
}

template<typename T>
void Stack<T>::pop() {
    if (empty()) {
        throw std::runtime_error("Cannot pop from empty stack");
    }
    data.pop_back();
}

template<typename T>
T& Stack<T>::top() {
    if (empty()) {
        throw std::runtime_error("Cannot access top of empty stack");
    }
    return data.back();
}

template<typename T>
const T& Stack<T>::top() const {
    if (empty()) {
        throw std::runtime_error("Cannot access top of empty stack");
    }
    return data.back();
}

template<typename T>
void Stack<T>::print() const {
    std::cout << "Stack (top to bottom): [";
    for (auto it = data.rbegin(); it != data.rend(); ++it) {
        std::cout << *it;
        if (it != data.rend() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}