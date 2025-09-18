#pragma once
#include <iostream>
#include <memory>

/**
 * @brief 链表节点 - Linked List Node
 */
template<typename T>
struct ListNode {
    T data;
    std::shared_ptr<ListNode<T>> next;
    
    explicit ListNode(const T& value) : data(value), next(nullptr) {}
};

/**
 * @brief 单向链表类 - Singly Linked List Class
 * 实现基本的链表操作，包括插入、删除、查找等
 */
template<typename T>
class LinkedList {
private:
    std::shared_ptr<ListNode<T>> head;
    size_t list_size;

public:
    LinkedList() : head(nullptr), list_size(0) {}
    ~LinkedList() = default;
    
    // 基本操作 - Basic Operations
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    
    // 插入和删除 - Insert and Delete
    void insert(size_t index, const T& value);
    void erase(size_t index);
    bool remove(const T& value);
    
    // 查找 - Search
    int find(const T& value) const;
    T& at(size_t index);
    const T& at(size_t index) const;
    
    // 属性 - Properties
    size_t size() const { return list_size; }
    bool empty() const { return list_size == 0; }
    
    // 打印 - Print
    void print() const;
    
    // 反转链表 - Reverse list
    void reverse();
};

template<typename T>
void LinkedList<T>::push_front(const T& value) {
    auto new_node = std::make_shared<ListNode<T>>(value);
    new_node->next = head;
    head = new_node;
    ++list_size;
}

template<typename T>
void LinkedList<T>::push_back(const T& value) {
    auto new_node = std::make_shared<ListNode<T>>(value);
    
    if (!head) {
        head = new_node;
    } else {
        auto current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
    ++list_size;
}

template<typename T>
void LinkedList<T>::pop_front() {
    if (empty()) {
        throw std::runtime_error("Cannot pop from empty list");
    }
    
    head = head->next;
    --list_size;
}

template<typename T>
void LinkedList<T>::pop_back() {
    if (empty()) {
        throw std::runtime_error("Cannot pop from empty list");
    }
    
    if (list_size == 1) {
        head = nullptr;
    } else {
        auto current = head;
        while (current->next && current->next->next) {
            current = current->next;
        }
        current->next = nullptr;
    }
    --list_size;
}

template<typename T>
void LinkedList<T>::insert(size_t index, const T& value) {
    if (index > list_size) {
        throw std::out_of_range("Index out of range");
    }
    
    if (index == 0) {
        push_front(value);
        return;
    }
    
    auto new_node = std::make_shared<ListNode<T>>(value);
    auto current = head;
    for (size_t i = 0; i < index - 1; ++i) {
        current = current->next;
    }
    
    new_node->next = current->next;
    current->next = new_node;
    ++list_size;
}

template<typename T>
void LinkedList<T>::erase(size_t index) {
    if (index >= list_size) {
        throw std::out_of_range("Index out of range");
    }
    
    if (index == 0) {
        pop_front();
        return;
    }
    
    auto current = head;
    for (size_t i = 0; i < index - 1; ++i) {
        current = current->next;
    }
    
    current->next = current->next->next;
    --list_size;
}

template<typename T>
bool LinkedList<T>::remove(const T& value) {
    if (empty()) return false;
    
    if (head->data == value) {
        pop_front();
        return true;
    }
    
    auto current = head;
    while (current->next && current->next->data != value) {
        current = current->next;
    }
    
    if (current->next) {
        current->next = current->next->next;
        --list_size;
        return true;
    }
    
    return false;
}

template<typename T>
int LinkedList<T>::find(const T& value) const {
    auto current = head;
    int index = 0;
    
    while (current) {
        if (current->data == value) {
            return index;
        }
        current = current->next;
        ++index;
    }
    
    return -1;
}

template<typename T>
T& LinkedList<T>::at(size_t index) {
    if (index >= list_size) {
        throw std::out_of_range("Index out of range");
    }
    
    auto current = head;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    
    return current->data;
}

template<typename T>
const T& LinkedList<T>::at(size_t index) const {
    if (index >= list_size) {
        throw std::out_of_range("Index out of range");
    }
    
    auto current = head;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    
    return current->data;
}

template<typename T>
void LinkedList<T>::print() const {
    std::cout << "[";
    auto current = head;
    bool first = true;
    
    while (current) {
        if (!first) std::cout << " -> ";
        std::cout << current->data;
        current = current->next;
        first = false;
    }
    std::cout << "]" << std::endl;
}

template<typename T>
void LinkedList<T>::reverse() {
    std::shared_ptr<ListNode<T>> prev = nullptr;
    auto current = head;
    
    while (current) {
        auto next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
}