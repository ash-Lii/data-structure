#include "data_structures.h"
#include <iostream>

int main() {
    std::cout << "=== 二叉搜索树示例 / Binary Search Tree Example ===" << std::endl;
    
    // 创建二叉搜索树
    BinarySearchTree<int> bst;
    
    // 插入元素
    std::cout << "插入元素: 50, 30, 70, 20, 40, 60, 80" << std::endl;
    std::vector<int> values = {50, 30, 70, 20, 40, 60, 80};
    for (int val : values) {
        bst.insert(val);
        std::cout << "插入 " << val << std::endl;
    }
    
    std::cout << "\n树的结构:" << std::endl;
    bst.print_structure();
    
    // 各种遍历方式
    std::cout << "\n=== 树的遍历 ===" << std::endl;
    bst.inorder();    // 中序遍历（有序）
    bst.preorder();   // 前序遍历
    bst.postorder();  // 后序遍历
    bst.level_order(); // 层序遍历
    
    // 查找元素
    std::cout << "\n=== 查找元素 ===" << std::endl;
    std::vector<int> search_values = {40, 25, 60, 90};
    for (int val : search_values) {
        bool found = bst.search(val);
        std::cout << "查找 " << val << ": " << (found ? "找到" : "未找到") << std::endl;
    }
    
    // 树的高度
    std::cout << "\n树的高度: " << bst.height() << std::endl;
    
    // 删除元素
    std::cout << "\n=== 删除元素 ===" << std::endl;
    
    // 删除叶子节点
    std::cout << "\n删除叶子节点 20:" << std::endl;
    bst.remove(20);
    bst.inorder();
    
    // 删除有一个子节点的节点
    std::cout << "\n删除有一个子节点的节点 30:" << std::endl;
    bst.remove(30);
    bst.inorder();
    
    // 删除有两个子节点的节点
    std::cout << "\n删除有两个子节点的节点 50 (根节点):" << std::endl;
    bst.remove(50);
    bst.inorder();
    
    std::cout << "\n删除后的树结构:" << std::endl;
    bst.print_structure();
    std::cout << "树的高度: " << bst.height() << std::endl;
    
    // 演示二叉搜索树的应用：查找范围内的元素
    std::cout << "\n=== 二叉搜索树应用：范围查找 ===" << std::endl;
    
    // 重新构建一个树进行演示
    BinarySearchTree<int> demo_bst;
    std::vector<int> demo_values = {15, 10, 20, 8, 12, 25, 6, 11, 13, 22, 27};
    
    std::cout << "构建新的二叉搜索树，插入元素: ";
    for (int val : demo_values) {
        demo_bst.insert(val);
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    demo_bst.inorder();
    
    // 模拟范围查找功能
    auto range_search = [&demo_bst](int min_val, int max_val) {
        std::cout << "查找范围 [" << min_val << ", " << max_val << "] 内的元素: ";
        
        // 简单的范围查找实现（通过中序遍历）
        std::vector<int> result;
        
        // 这里为了演示，我们用一个简化的方法
        for (int i = min_val; i <= max_val; ++i) {
            if (demo_bst.search(i)) {
                result.push_back(i);
            }
        }
        
        for (int val : result) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    };
    
    range_search(10, 15);
    range_search(20, 30);
    range_search(5, 9);
    
    return 0;
}