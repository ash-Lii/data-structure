#include "data_structures.h"
#include <iostream>

int main() {
    std::cout << "=== 栈示例 / Stack Example ===" << std::endl;
    
    // 创建栈
    Stack<int> stack;
    
    // 压栈操作
    std::cout << "压栈元素 1, 2, 3, 4, 5:" << std::endl;
    for (int i = 1; i <= 5; ++i) {
        stack.push(i);
        std::cout << "压入 " << i << ", 栈顶元素: " << stack.top() << std::endl;
    }
    
    std::cout << "\n当前栈状态:" << std::endl;
    stack.print();
    
    // 出栈操作
    std::cout << "\n出栈操作:" << std::endl;
    while (!stack.empty()) {
        std::cout << "栈顶元素: " << stack.top() << " -> 出栈" << std::endl;
        stack.pop();
        
        if (!stack.empty()) {
            std::cout << "新的栈顶元素: " << stack.top() << std::endl;
        } else {
            std::cout << "栈现在为空" << std::endl;
        }
        
        std::cout << "当前栈大小: " << stack.size() << std::endl;
        std::cout << "---" << std::endl;
    }
    
    // 演示栈的应用：括号匹配
    std::cout << "\n=== 栈的应用：括号匹配检查 ===" << std::endl;
    
    auto check_parentheses = [](const std::string& expr) {
        Stack<char> paren_stack;
        
        for (char c : expr) {
            if (c == '(' || c == '[' || c == '{') {
                paren_stack.push(c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (paren_stack.empty()) {
                    return false;
                }
                
                char top = paren_stack.top();
                paren_stack.pop();
                
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    return false;
                }
            }
        }
        
        return paren_stack.empty();
    };
    
    std::vector<std::string> test_cases = {
        "()",
        "()[]{}",
        "([{}])",
        "((()))",
        "([)]",
        "(((",
        "))",
        ""
    };
    
    for (const auto& test : test_cases) {
        bool is_valid = check_parentheses(test);
        std::cout << "表达式 \"" << test << "\" 括号匹配: " 
                  << (is_valid ? "正确" : "错误") << std::endl;
    }
    
    return 0;
}