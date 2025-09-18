#pragma once
#include <iostream>
#include <deque>
#include <stdexcept>

/**
 * @brief 队列类 - Queue Class
 * 基于双端队列实现的队列（FIFO - First In First Out）
 */
template<typename T>
class Queue {
private:
    std::deque<T> data;

public:
    Queue() = default;
    
    // 队列操作 - Queue Operations
    void enqueue(const T& value);  // 入队
    void dequeue();                // 出队
    T& front();                    // 队首元素
    const T& front() const;
    T& back();                     // 队尾元素
    const T& back() const;
    
    // 属性 - Properties
    size_t size() const { return data.size(); }
    bool empty() const { return data.empty(); }
    
    // 打印 - Print
    void print() const;
};

template<typename T>
void Queue<T>::enqueue(const T& value) {
    data.push_back(value);
}

template<typename T>
void Queue<T>::dequeue() {
    if (empty()) {
        throw std::runtime_error("Cannot dequeue from empty queue");
    }
    data.pop_front();
}

template<typename T>
T& Queue<T>::front() {
    if (empty()) {
        throw std::runtime_error("Cannot access front of empty queue");
    }
    return data.front();
}

template<typename T>
const T& Queue<T>::front() const {
    if (empty()) {
        throw std::runtime_error("Cannot access front of empty queue");
    }
    return data.front();
}

template<typename T>
T& Queue<T>::back() {
    if (empty()) {
        throw std::runtime_error("Cannot access back of empty queue");
    }
    return data.back();
}

template<typename T>
const T& Queue<T>::back() const {
    if (empty()) {
        throw std::runtime_error("Cannot access back of empty queue");
    }
    return data.back();
}

template<typename T>
void Queue<T>::print() const {
    std::cout << "Queue (front to back): [";
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i];
        if (i < data.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}