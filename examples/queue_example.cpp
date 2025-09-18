#include "data_structures.h"
#include <iostream>

int main() {
    std::cout << "=== 队列示例 / Queue Example ===" << std::endl;
    
    // 创建队列
    Queue<int> queue;
    
    // 入队操作
    std::cout << "入队元素 1, 2, 3, 4, 5:" << std::endl;
    for (int i = 1; i <= 5; ++i) {
        queue.enqueue(i);
        std::cout << "入队 " << i << ", 队首: " << queue.front() 
                  << ", 队尾: " << queue.back() << std::endl;
    }
    
    std::cout << "\n当前队列状态:" << std::endl;
    queue.print();
    
    // 出队操作
    std::cout << "\n出队操作:" << std::endl;
    while (!queue.empty()) {
        std::cout << "队首元素: " << queue.front() << " -> 出队" << std::endl;
        queue.dequeue();
        
        if (!queue.empty()) {
            std::cout << "新的队首元素: " << queue.front() << std::endl;
            std::cout << "队尾元素: " << queue.back() << std::endl;
        } else {
            std::cout << "队列现在为空" << std::endl;
        }
        
        std::cout << "当前队列大小: " << queue.size() << std::endl;
        std::cout << "---" << std::endl;
    }
    
    // 演示队列的应用：模拟银行排队系统
    std::cout << "\n=== 队列的应用：银行排队系统模拟 ===" << std::endl;
    
    struct Customer {
        int id;
        std::string name;
        
        Customer(int i, const std::string& n) : id(i), name(n) {}
    };
    
    // 重载输出操作符以便打印Customer
    auto print_customer = [](const Customer& c) {
        return "顾客" + std::to_string(c.id) + "(" + c.name + ")";
    };
    
    Queue<Customer> bank_queue;
    
    // 顾客到达
    std::cout << "\n顾客陆续到达银行:" << std::endl;
    std::vector<Customer> customers = {
        {1, "张三"}, {2, "李四"}, {3, "王五"}, {4, "赵六"}
    };
    
    for (const auto& customer : customers) {
        bank_queue.enqueue(customer);
        std::cout << print_customer(customer) << " 进入队列" << std::endl;
        std::cout << "当前队列长度: " << bank_queue.size() << std::endl;
        if (!bank_queue.empty()) {
            std::cout << "下一位服务的是: " << print_customer(bank_queue.front()) << std::endl;
        }
        std::cout << "---" << std::endl;
    }
    
    // 服务顾客
    std::cout << "\n开始服务顾客:" << std::endl;
    int service_time = 1;
    while (!bank_queue.empty()) {
        Customer current = bank_queue.front();
        bank_queue.dequeue();
        
        std::cout << "第" << service_time << "个服务窗口正在服务: " 
                  << print_customer(current) << std::endl;
        std::cout << "剩余队列长度: " << bank_queue.size() << std::endl;
        
        if (!bank_queue.empty()) {
            std::cout << "下一位: " << print_customer(bank_queue.front()) << std::endl;
        }
        std::cout << "---" << std::endl;
        service_time++;
    }
    
    std::cout << "所有顾客已服务完毕！" << std::endl;
    
    return 0;
}