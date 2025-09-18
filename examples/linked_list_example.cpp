#include "data_structures.h"
#include <iostream>

int main() {
    std::cout << "=== 链表示例 / Linked List Example ===" << std::endl;
    
    // 创建链表
    LinkedList<int> list;
    
    // 在头部添加元素
    std::cout << "在头部添加元素 3, 2, 1:" << std::endl;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    list.print();
    
    // 在尾部添加元素
    std::cout << "\n在尾部添加元素 4, 5:" << std::endl;
    list.push_back(4);
    list.push_back(5);
    list.print();
    
    // 在指定位置插入元素
    std::cout << "\n在索引2处插入元素10:" << std::endl;
    list.insert(2, 10);
    list.print();
    
    // 查找元素
    std::cout << "\n查找元素3的位置: " << list.find(3) << std::endl;
    std::cout << "查找元素10的位置: " << list.find(10) << std::endl;
    std::cout << "查找元素99的位置: " << list.find(99) << std::endl;
    
    // 访问元素
    std::cout << "\n访问索引0的元素: " << list.at(0) << std::endl;
    std::cout << "访问索引3的元素: " << list.at(3) << std::endl;
    
    // 删除元素
    std::cout << "\n删除索引2的元素(10):" << std::endl;
    list.erase(2);
    list.print();
    
    // 删除指定值的元素
    std::cout << "\n删除值为3的元素:" << std::endl;
    bool removed = list.remove(3);
    std::cout << "删除" << (removed ? "成功" : "失败") << std::endl;
    list.print();
    
    // 反转链表
    std::cout << "\n反转链表:" << std::endl;
    list.reverse();
    list.print();
    
    // 删除头部和尾部元素
    std::cout << "\n删除头部元素:" << std::endl;
    list.pop_front();
    list.print();
    
    std::cout << "\n删除尾部元素:" << std::endl;
    list.pop_back();
    list.print();
    
    std::cout << "\n链表大小: " << list.size() << std::endl;
    std::cout << "链表是否为空: " << (list.empty() ? "是" : "否") << std::endl;
    
    return 0;
}