#include"header_files.h"
/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
struct listNode {
    listNode* next;
    listNode* before;
    int key;
    int val;
    listNode(int key_) : key(key_), next(nullptr), before(nullptr) {}
    listNode() : key(0), next(nullptr), before(nullptr) {}
};
class LRUCache {
private:
    int capacity;
    unordered_map<int,listNode*> reserve;
    listNode* start;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        listNode dummy;
        start=&dummy;
    }
    
    int get(int key) {
        
    }
    
    void put(int key, int value) {
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

