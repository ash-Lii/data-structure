#pragma once
#include <iostream>
#include <memory>
#include <queue>

/**
 * @brief 二叉树节点 - Binary Tree Node
 */
template<typename T>
struct TreeNode {
    T data;
    std::shared_ptr<TreeNode<T>> left;
    std::shared_ptr<TreeNode<T>> right;
    
    explicit TreeNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

/**
 * @brief 二叉搜索树类 - Binary Search Tree Class
 * 实现基本的二叉搜索树操作
 */
template<typename T>
class BinarySearchTree {
private:
    std::shared_ptr<TreeNode<T>> root;
    
    // 辅助函数 - Helper functions
    std::shared_ptr<TreeNode<T>> insert_helper(std::shared_ptr<TreeNode<T>> node, const T& value);
    std::shared_ptr<TreeNode<T>> remove_helper(std::shared_ptr<TreeNode<T>> node, const T& value);
    std::shared_ptr<TreeNode<T>> find_min(std::shared_ptr<TreeNode<T>> node);
    bool search_helper(std::shared_ptr<TreeNode<T>> node, const T& value) const;
    void inorder_helper(std::shared_ptr<TreeNode<T>> node) const;
    void preorder_helper(std::shared_ptr<TreeNode<T>> node) const;
    void postorder_helper(std::shared_ptr<TreeNode<T>> node) const;
    int height_helper(std::shared_ptr<TreeNode<T>> node) const;

public:
    BinarySearchTree() : root(nullptr) {}
    
    // 基本操作 - Basic Operations
    void insert(const T& value);
    void remove(const T& value);
    bool search(const T& value) const;
    
    // 遍历 - Traversal
    void inorder() const;    // 中序遍历
    void preorder() const;   // 前序遍历
    void postorder() const;  // 后序遍历
    void level_order() const; // 层序遍历
    
    // 属性 - Properties
    bool empty() const { return root == nullptr; }
    int height() const;
    
    // 打印树结构 - Print tree structure
    void print_structure() const;
};

template<typename T>
void BinarySearchTree<T>::insert(const T& value) {
    root = insert_helper(root, value);
}

template<typename T>
std::shared_ptr<TreeNode<T>> BinarySearchTree<T>::insert_helper(std::shared_ptr<TreeNode<T>> node, const T& value) {
    if (!node) {
        return std::make_shared<TreeNode<T>>(value);
    }
    
    if (value < node->data) {
        node->left = insert_helper(node->left, value);
    } else if (value > node->data) {
        node->right = insert_helper(node->right, value);
    }
    // 如果值相等，不插入重复值
    
    return node;
}

template<typename T>
void BinarySearchTree<T>::remove(const T& value) {
    root = remove_helper(root, value);
}

template<typename T>
std::shared_ptr<TreeNode<T>> BinarySearchTree<T>::remove_helper(std::shared_ptr<TreeNode<T>> node, const T& value) {
    if (!node) return node;
    
    if (value < node->data) {
        node->left = remove_helper(node->left, value);
    } else if (value > node->data) {
        node->right = remove_helper(node->right, value);
    } else {
        // 找到要删除的节点
        if (!node->left) {
            return node->right;
        } else if (!node->right) {
            return node->left;
        }
        
        // 节点有两个子节点
        auto min_node = find_min(node->right);
        node->data = min_node->data;
        node->right = remove_helper(node->right, min_node->data);
    }
    
    return node;
}

template<typename T>
std::shared_ptr<TreeNode<T>> BinarySearchTree<T>::find_min(std::shared_ptr<TreeNode<T>> node) {
    while (node->left) {
        node = node->left;
    }
    return node;
}

template<typename T>
bool BinarySearchTree<T>::search(const T& value) const {
    return search_helper(root, value);
}

template<typename T>
bool BinarySearchTree<T>::search_helper(std::shared_ptr<TreeNode<T>> node, const T& value) const {
    if (!node) return false;
    
    if (value == node->data) return true;
    if (value < node->data) return search_helper(node->left, value);
    return search_helper(node->right, value);
}

template<typename T>
void BinarySearchTree<T>::inorder() const {
    std::cout << "Inorder traversal: ";
    inorder_helper(root);
    std::cout << std::endl;
}

template<typename T>
void BinarySearchTree<T>::inorder_helper(std::shared_ptr<TreeNode<T>> node) const {
    if (node) {
        inorder_helper(node->left);
        std::cout << node->data << " ";
        inorder_helper(node->right);
    }
}

template<typename T>
void BinarySearchTree<T>::preorder() const {
    std::cout << "Preorder traversal: ";
    preorder_helper(root);
    std::cout << std::endl;
}

template<typename T>
void BinarySearchTree<T>::preorder_helper(std::shared_ptr<TreeNode<T>> node) const {
    if (node) {
        std::cout << node->data << " ";
        preorder_helper(node->left);
        preorder_helper(node->right);
    }
}

template<typename T>
void BinarySearchTree<T>::postorder() const {
    std::cout << "Postorder traversal: ";
    postorder_helper(root);
    std::cout << std::endl;
}

template<typename T>
void BinarySearchTree<T>::postorder_helper(std::shared_ptr<TreeNode<T>> node) const {
    if (node) {
        postorder_helper(node->left);
        postorder_helper(node->right);
        std::cout << node->data << " ";
    }
}

template<typename T>
void BinarySearchTree<T>::level_order() const {
    if (!root) {
        std::cout << "Level order traversal: (empty tree)" << std::endl;
        return;
    }
    
    std::cout << "Level order traversal: ";
    std::queue<std::shared_ptr<TreeNode<T>>> q;
    q.push(root);
    
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        
        std::cout << current->data << " ";
        
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    std::cout << std::endl;
}

template<typename T>
int BinarySearchTree<T>::height() const {
    return height_helper(root);
}

template<typename T>
int BinarySearchTree<T>::height_helper(std::shared_ptr<TreeNode<T>> node) const {
    if (!node) return 0;
    
    int left_height = height_helper(node->left);
    int right_height = height_helper(node->right);
    
    return 1 + std::max(left_height, right_height);
}

template<typename T>
void BinarySearchTree<T>::print_structure() const {
    if (!root) {
        std::cout << "Tree is empty" << std::endl;
        return;
    }
    std::cout << "Binary Search Tree structure:" << std::endl;
    level_order();
}