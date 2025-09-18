#!/bin/bash

# 数据结构学习项目快速启动脚本
# Quick start script for Data Structure Learning Project

echo "=== 数据结构学习项目 / Data Structure Learning Project ==="
echo ""

# 检查是否已构建
if [ ! -d "build" ]; then
    echo "首次运行，正在构建项目... / First run, building project..."
    make build
    echo ""
fi

echo "选择要运行的示例 / Choose an example to run:"
echo "1. 动态数组 / Dynamic Array"
echo "2. 链表 / Linked List"
echo "3. 栈 / Stack"
echo "4. 队列 / Queue"
echo "5. 二叉搜索树 / Binary Search Tree"
echo "6. 哈希表 / Hash Table"
echo "7. 运行所有示例 / Run all examples"
echo "8. 退出 / Exit"
echo ""

read -p "请输入选择 (1-8) / Please enter your choice (1-8): " choice

case $choice in
    1)
        echo "运行动态数组示例 / Running Dynamic Array example..."
        make array
        ;;
    2)
        echo "运行链表示例 / Running Linked List example..."
        make linked-list
        ;;
    3)
        echo "运行栈示例 / Running Stack example..."
        make stack
        ;;
    4)
        echo "运行队列示例 / Running Queue example..."
        make queue
        ;;
    5)
        echo "运行二叉搜索树示例 / Running Binary Search Tree example..."
        make binary-tree
        ;;
    6)
        echo "运行哈希表示例 / Running Hash Table example..."
        make hash-table
        ;;
    7)
        echo "运行所有示例 / Running all examples..."
        make examples
        ;;
    8)
        echo "退出 / Exiting..."
        exit 0
        ;;
    *)
        echo "无效选择 / Invalid choice"
        exit 1
        ;;
esac

echo ""
echo "完成! / Completed!"