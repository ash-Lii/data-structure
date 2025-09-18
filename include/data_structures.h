#pragma once

/**
 * @file data_structures.h
 * @brief 数据结构学习库 - Data Structures Learning Library
 * @author C++ Data Structure Learning Project
 * 
 * 本文件包含了常用数据结构的C++实现，用于学习和理解数据结构的原理
 * This file contains C++ implementations of common data structures for learning purposes
 */

#include "data_structures/dynamic_array.h"
#include "data_structures/linked_list.h"
#include "data_structures/stack.h"
#include "data_structures/queue.h"
#include "data_structures/binary_tree.h"
#include "data_structures/hash_table.h"

namespace ds {
    // 类型别名 - Type aliases for convenience
    template<typename T>
    using Array = DynamicArray<T>;
    
    template<typename T>
    using List = LinkedList<T>;
    
    template<typename T>
    using BST = BinarySearchTree<T>;
    
    template<typename K, typename V>
    using HashMap = HashTable<K, V>;
}

/**
 * @brief 打印库信息 - Print library information
 */
inline void print_library_info() {
    std::cout << "=== C++ 数据结构学习库 / C++ Data Structures Learning Library ===" << std::endl;
    std::cout << "包含的数据结构 / Included Data Structures:" << std::endl;
    std::cout << "1. 动态数组 / Dynamic Array" << std::endl;
    std::cout << "2. 链表 / Linked List" << std::endl;
    std::cout << "3. 栈 / Stack" << std::endl;
    std::cout << "4. 队列 / Queue" << std::endl;
    std::cout << "5. 二叉搜索树 / Binary Search Tree" << std::endl;
    std::cout << "6. 哈希表 / Hash Table" << std::endl;
    std::cout << "=========================================" << std::endl;
}