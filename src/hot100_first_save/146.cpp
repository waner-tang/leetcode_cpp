#include"header_files.h"
/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
struct DlinkedNode
{
    int key;
    int value;
    DlinkedNode * prev;
    DlinkedNode * next;
    DlinkedNode():key(0),value(0),prev(nullptr),next(nullptr){}
    DlinkedNode(int _key, int _value):key(_key),value(_value),prev(nullptr),next(nullptr){}
};
class LRUCache {
private:
    int capacity;
    unordered_map<int,DlinkedNode *> reserve;
    DlinkedNode * head;
    DlinkedNode * tail;
public:
    LRUCache(int _capacity) {
        capacity=_capacity;
        // 制造伪头节点与伪尾节点
        head=new DlinkedNode();
        tail=new DlinkedNode();
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if (reserve.find(key)!=reserve.end())
        {
            DlinkedNode * curr=reserve[key];
            removeNode(curr);
            addToHead(curr);
            return head->next->value;
        }
        else
        {
            return -1;
        }
        
    }
    
    void put(int key, int value) {
        if (reserve.find(key)!=reserve.end())
        {
            DlinkedNode * curr=reserve[key];
            removeNode(curr);
            addToHead(curr);
            curr->value=value;
        }
        else
        {
            DlinkedNode * curr=new DlinkedNode(key,value);
            reserve[key]=curr;
            addToHead(curr);
            if (reserve.size()>capacity)
            {
                DlinkedNode * re=removeTail();
                reserve.erase(reserve.find(re->key));
                delete re;
            }
            
        }
        
    }

    void removeNode(DlinkedNode * curr)
    {
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
    }
    void addToHead(DlinkedNode * curr)
    {
        curr->prev=head;
        curr->next=head->next;
        head->next->prev=curr;
        head->next=curr;
    }
    DlinkedNode * removeTail()
    {
        DlinkedNode * curr=tail->prev;
        curr->prev->next=tail;
        tail->prev=curr->prev;
        return curr;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

