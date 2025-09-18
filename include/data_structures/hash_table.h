#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <functional>

/**
 * @brief 哈希表类 - Hash Table Class
 * 使用链地址法解决冲突的哈希表实现
 */
template<typename K, typename V>
class HashTable {
private:
    static const size_t DEFAULT_BUCKET_COUNT = 16;
    static const double MAX_LOAD_FACTOR;
    
    struct KeyValuePair {
        K key;
        V value;
        KeyValuePair(const K& k, const V& v) : key(k), value(v) {}
    };
    
    std::vector<std::list<KeyValuePair>> buckets;
    size_t bucket_count;
    size_t table_size;
    
    // 哈希函数 - Hash function
    size_t hash(const K& key) const;
    
    // 重新哈希 - Rehashing
    void rehash();

public:
    HashTable(size_t initial_bucket_count = DEFAULT_BUCKET_COUNT);
    
    // 基本操作 - Basic Operations
    void insert(const K& key, const V& value);
    bool remove(const K& key);
    bool find(const K& key, V& value) const;
    bool contains(const K& key) const;
    
    // 操作符重载 - Operator overloading
    V& operator[](const K& key);
    
    // 属性 - Properties
    size_t size() const { return table_size; }
    bool empty() const { return table_size == 0; }
    double load_factor() const { return static_cast<double>(table_size) / bucket_count; }
    
    // 打印 - Print
    void print() const;
};

template<typename K, typename V>
const double HashTable<K, V>::MAX_LOAD_FACTOR = 0.75;

template<typename K, typename V>
HashTable<K, V>::HashTable(size_t initial_bucket_count) 
    : bucket_count(initial_bucket_count), table_size(0) {
    buckets.resize(bucket_count);
}

template<typename K, typename V>
size_t HashTable<K, V>::hash(const K& key) const {
    return std::hash<K>{}(key) % bucket_count;
}

template<typename K, typename V>
void HashTable<K, V>::insert(const K& key, const V& value) {
    size_t index = hash(key);
    
    // 检查是否已存在该键
    for (auto& pair : buckets[index]) {
        if (pair.key == key) {
            pair.value = value;  // 更新值
            return;
        }
    }
    
    // 插入新的键值对
    buckets[index].emplace_back(key, value);
    ++table_size;
    
    // 检查是否需要重新哈希
    if (load_factor() > MAX_LOAD_FACTOR) {
        rehash();
    }
}

template<typename K, typename V>
bool HashTable<K, V>::remove(const K& key) {
    size_t index = hash(key);
    
    auto& bucket = buckets[index];
    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
        if (it->key == key) {
            bucket.erase(it);
            --table_size;
            return true;
        }
    }
    
    return false;
}

template<typename K, typename V>
bool HashTable<K, V>::find(const K& key, V& value) const {
    size_t index = hash(key);
    
    for (const auto& pair : buckets[index]) {
        if (pair.key == key) {
            value = pair.value;
            return true;
        }
    }
    
    return false;
}

template<typename K, typename V>
bool HashTable<K, V>::contains(const K& key) const {
    size_t index = hash(key);
    
    for (const auto& pair : buckets[index]) {
        if (pair.key == key) {
            return true;
        }
    }
    
    return false;
}

template<typename K, typename V>
V& HashTable<K, V>::operator[](const K& key) {
    size_t index = hash(key);
    
    // 查找现有键
    for (auto& pair : buckets[index]) {
        if (pair.key == key) {
            return pair.value;
        }
    }
    
    // 如果键不存在，插入默认值
    buckets[index].emplace_back(key, V{});
    ++table_size;
    
    if (load_factor() > MAX_LOAD_FACTOR) {
        rehash();
        // 重新计算索引
        index = hash(key);
        for (auto& pair : buckets[index]) {
            if (pair.key == key) {
                return pair.value;
            }
        }
    }
    
    return buckets[index].back().value;
}

template<typename K, typename V>
void HashTable<K, V>::rehash() {
    std::vector<std::list<KeyValuePair>> old_buckets = std::move(buckets);
    bucket_count *= 2;
    buckets.clear();
    buckets.resize(bucket_count);
    table_size = 0;
    
    // 重新插入所有元素
    for (const auto& bucket : old_buckets) {
        for (const auto& pair : bucket) {
            insert(pair.key, pair.value);
        }
    }
}

template<typename K, typename V>
void HashTable<K, V>::print() const {
    std::cout << "Hash Table (size: " << table_size << ", buckets: " << bucket_count 
              << ", load factor: " << load_factor() << "):" << std::endl;
    
    for (size_t i = 0; i < bucket_count; ++i) {
        std::cout << "Bucket " << i << ": ";
        for (const auto& pair : buckets[i]) {
            std::cout << "[" << pair.key << ":" << pair.value << "] ";
        }
        std::cout << std::endl;
    }
}