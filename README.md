# 数据结构学习 / Data Structure Learning

本项目使用C++实现了常见的数据结构，旨在帮助学习和理解数据结构的基本概念和操作。

This project implements common data structures using C++ to help learn and understand fundamental concepts and operations of data structures.

## 🏗️ 项目结构 / Project Structure

```
data-structure/
├── include/                    # 头文件目录
│   ├── data_structures.h      # 主头文件
│   └── data_structures/       # 各数据结构头文件
│       ├── dynamic_array.h    # 动态数组
│       ├── linked_list.h      # 链表
│       ├── stack.h            # 栈
│       ├── queue.h            # 队列
│       ├── binary_tree.h      # 二叉搜索树
│       └── hash_table.h       # 哈希表
├── src/                       # 源文件目录
│   └── data_structures.cpp   # 实现文件
├── examples/                  # 示例程序
│   ├── array_example.cpp     # 动态数组示例
│   ├── linked_list_example.cpp # 链表示例
│   ├── stack_example.cpp     # 栈示例
│   ├── queue_example.cpp     # 队列示例
│   ├── binary_tree_example.cpp # 二叉树示例
│   └── hash_table_example.cpp # 哈希表示例
├── build/                     # 构建目录
├── CMakeLists.txt            # CMake构建配置
└── README.md                 # 项目说明
```

## 📚 包含的数据结构 / Included Data Structures

### 1. 动态数组 (Dynamic Array)
- **功能**: 可动态调整大小的数组
- **操作**: 插入、删除、查找、随机访问
- **时间复杂度**: 访问 O(1)，插入/删除 O(n)
- **特点**: 支持迭代器遍历

### 2. 单向链表 (Singly Linked List)
- **功能**: 基于节点的线性数据结构
- **操作**: 前/后插入、删除、查找、反转
- **时间复杂度**: 插入/删除 O(1)，查找 O(n)
- **特点**: 动态内存分配，无需预定义大小

### 3. 栈 (Stack)
- **功能**: 后进先出 (LIFO) 数据结构
- **操作**: push(入栈), pop(出栈), top(栈顶)
- **时间复杂度**: 所有操作 O(1)
- **应用**: 括号匹配、表达式求值、函数调用

### 4. 队列 (Queue)
- **功能**: 先进先出 (FIFO) 数据结构
- **操作**: enqueue(入队), dequeue(出队), front/back
- **时间复杂度**: 所有操作 O(1)
- **应用**: 任务调度、广度优先搜索

### 5. 二叉搜索树 (Binary Search Tree)
- **功能**: 有序的树形数据结构
- **操作**: 插入、删除、查找、遍历
- **时间复杂度**: 平均 O(log n)，最坏 O(n)
- **遍历**: 前序、中序、后序、层序

### 6. 哈希表 (Hash Table)
- **功能**: 基于哈希函数的键值对存储
- **操作**: 插入、删除、查找
- **时间复杂度**: 平均 O(1)，最坏 O(n)
- **冲突解决**: 链地址法，自动重新哈希

## 🚀 快速开始 / Quick Start

### 环境要求 / Requirements
- C++17 或更高版本
- CMake 3.10 或更高版本
- 支持C++标准库的编译器 (GCC, Clang, MSVC)

### 编译和运行 / Build and Run

```bash
# 克隆项目
git clone <repository-url>
cd data-structure

# 创建构建目录
mkdir build
cd build

# 使用CMake配置和编译
cmake ..
make

# 运行示例程序
./array_example          # 动态数组示例
./linked_list_example    # 链表示例
./stack_example          # 栈示例
./queue_example          # 队列示例
./binary_tree_example    # 二叉树示例
./hash_table_example     # 哈希表示例
```

## 💡 使用示例 / Usage Examples

### 基本使用
```cpp
#include "data_structures.h"
#include <iostream>

int main() {
    // 使用动态数组
    DynamicArray<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.print();  // 输出: [1, 2]
    
    // 使用栈
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    std::cout << stack.top() << std::endl;  // 输出: 20
    
    // 使用哈希表
    HashTable<std::string, int> table;
    table["apple"] = 5;
    table["banana"] = 3;
    std::cout << table["apple"] << std::endl;  // 输出: 5
    
    return 0;
}
```

### 命名空间别名
```cpp
#include "data_structures.h"

int main() {
    // 使用命名空间别名简化代码
    ds::Array<int> arr;           // 等同于 DynamicArray<int>
    ds::List<std::string> list;   // 等同于 LinkedList<std::string>
    ds::BST<int> tree;           // 等同于 BinarySearchTree<int>
    ds::HashMap<std::string, int> map;  // 等同于 HashTable<std::string, int>
    
    return 0;
}
```

## 🎯 学习目标 / Learning Objectives

通过本项目，你将学习到：

1. **数据结构基础概念**
   - 线性结构 vs 非线性结构
   - 静态结构 vs 动态结构
   - 时间复杂度和空间复杂度分析

2. **具体数据结构的实现**
   - 各种数据结构的内部实现原理
   - 不同操作的算法实现
   - 性能特点和使用场景

3. **C++编程技能**
   - 模板编程
   - 智能指针的使用
   - RAII设计模式
   - 异常处理

4. **算法思维**
   - 递归算法（树的遍历）
   - 哈希算法
   - 查找和排序算法

## 📖 深入学习 / Advanced Learning

### 扩展练习
1. 实现双向链表
2. 添加平衡二叉树（AVL树、红黑树）
3. 实现图数据结构
4. 添加更多哈希冲突解决方法
5. 实现线程安全版本

### 性能分析
每个示例程序都包含了性能分析和实际应用场景，帮助理解何时使用哪种数据结构。

## 🔧 技术特点 / Technical Features

- **Header-only库**: 大部分实现在头文件中，方便使用
- **模板化设计**: 支持任意数据类型
- **异常安全**: 适当的错误处理和异常抛出
- **现代C++**: 使用C++17标准和现代C++特性
- **内存安全**: 使用智能指针避免内存泄漏
- **注释完整**: 中英文双语注释，便于理解

## 🤝 贡献 / Contributing

欢迎贡献代码、报告问题或提出改进建议！

## 📄 许可证 / License

本项目采用 MIT 许可证。详见 LICENSE 文件。

---

**快乐学习数据结构！ / Happy Learning Data Structures!** 🎉
