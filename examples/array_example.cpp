#include "data_structures.h"
#include <iostream>

int main() {
    std::cout << "=== 动态数组示例 / Dynamic Array Example ===" << std::endl;
    
    // 创建动态数组
    DynamicArray<int> arr;
    
    // 添加元素
    std::cout << "添加元素 1, 2, 3, 4, 5:" << std::endl;
    for (int i = 1; i <= 5; ++i) {
        arr.push_back(i);
    }
    arr.print();
    
    // 在索引2处插入元素10
    std::cout << "\n在索引2处插入10:" << std::endl;
    arr.insert(2, 10);
    arr.print();
    
    // 查找元素
    std::cout << "\n查找元素3的位置: " << arr.find(3) << std::endl;
    std::cout << "查找元素10的位置: " << arr.find(10) << std::endl;
    
    // 访问元素
    std::cout << "\n访问索引0的元素: " << arr.at(0) << std::endl;
    std::cout << "访问索引3的元素: " << arr.at(3) << std::endl;
    
    // 删除元素
    std::cout << "\n删除索引2的元素(10):" << std::endl;
    arr.erase(2);
    arr.print();
    
    // 删除最后一个元素
    std::cout << "\n删除最后一个元素:" << std::endl;
    arr.pop_back();
    arr.print();
    
    // 使用迭代器遍历
    std::cout << "\n使用迭代器遍历数组:" << std::endl;
    std::cout << "元素: ";
    for (const auto& element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n数组大小: " << arr.size() << std::endl;
    std::cout << "数组是否为空: " << (arr.empty() ? "是" : "否") << std::endl;
    
    return 0;
}