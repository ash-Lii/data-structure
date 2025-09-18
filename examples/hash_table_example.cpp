#include "data_structures.h"
#include <iostream>

int main() {
    std::cout << "=== 哈希表示例 / Hash Table Example ===" << std::endl;
    
    // 创建哈希表
    HashTable<std::string, int> hash_table;
    
    // 插入键值对
    std::cout << "插入学生成绩数据:" << std::endl;
    hash_table.insert("张三", 85);
    hash_table.insert("李四", 92);
    hash_table.insert("王五", 78);
    hash_table.insert("赵六", 96);
    hash_table.insert("钱七", 88);
    
    std::cout << "初始哈希表状态:" << std::endl;
    hash_table.print();
    
    // 查找元素
    std::cout << "\n=== 查找元素 ===" << std::endl;
    std::vector<std::string> students = {"张三", "李四", "孙八", "王五"};
    
    for (const auto& student : students) {
        int score;
        bool found = hash_table.find(student, score);
        std::cout << "查找 " << student << ": ";
        if (found) {
            std::cout << "成绩 " << score << std::endl;
        } else {
            std::cout << "未找到" << std::endl;
        }
    }
    
    // 使用 contains 方法检查
    std::cout << "\n使用 contains 方法检查:" << std::endl;
    for (const auto& student : students) {
        bool exists = hash_table.contains(student);
        std::cout << student << (exists ? " 存在" : " 不存在") << std::endl;
    }
    
    // 使用操作符[]访问和修改
    std::cout << "\n=== 使用操作符[] ===" << std::endl;
    std::cout << "张三的成绩: " << hash_table["张三"] << std::endl;
    
    // 修改成绩
    hash_table["张三"] = 90;
    std::cout << "修改张三的成绩为90" << std::endl;
    std::cout << "张三的新成绩: " << hash_table["张三"] << std::endl;
    
    // 添加新学生（如果不存在会自动创建）
    hash_table["周八"] = 95;
    std::cout << "添加新学生周八，成绩95" << std::endl;
    
    std::cout << "\n更新后的哈希表:" << std::endl;
    hash_table.print();
    
    // 删除元素
    std::cout << "\n=== 删除元素 ===" << std::endl;
    bool removed = hash_table.remove("王五");
    std::cout << "删除王五: " << (removed ? "成功" : "失败") << std::endl;
    
    removed = hash_table.remove("不存在的学生");
    std::cout << "删除不存在的学生: " << (removed ? "成功" : "失败") << std::endl;
    
    std::cout << "\n删除后的哈希表:" << std::endl;
    hash_table.print();
    
    // 演示负载因子和重新哈希
    std::cout << "\n=== 负载因子和重新哈希演示 ===" << std::endl;
    
    HashTable<int, std::string> number_table(4); // 较小的初始大小
    
    std::cout << "创建初始大小为4的哈希表，插入多个元素观察重新哈希:" << std::endl;
    
    for (int i = 1; i <= 10; ++i) {
        std::string value = "值" + std::to_string(i);
        number_table.insert(i, value);
        std::cout << "插入 (" << i << ", " << value << ") - "
                  << "负载因子: " << number_table.load_factor() 
                  << ", 大小: " << number_table.size() << std::endl;
    }
    
    std::cout << "\n最终哈希表状态:" << std::endl;
    number_table.print();
    
    // 演示哈希表的应用：单词计数
    std::cout << "\n=== 哈希表应用：单词计数 ===" << std::endl;
    
    HashTable<std::string, int> word_count;
    std::vector<std::string> words = {
        "apple", "banana", "apple", "orange", "banana", "apple", 
        "grape", "orange", "banana", "apple"
    };
    
    std::cout << "统计单词出现次数: ";
    for (const auto& word : words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    
    for (const auto& word : words) {
        if (word_count.contains(word)) {
            word_count[word]++;
        } else {
            word_count[word] = 1;
        }
    }
    
    std::cout << "\n单词计数结果:" << std::endl;
    std::vector<std::string> unique_words = {"apple", "banana", "orange", "grape"};
    for (const auto& word : unique_words) {
        std::cout << word << ": " << word_count[word] << " 次" << std::endl;
    }
    
    return 0;
}