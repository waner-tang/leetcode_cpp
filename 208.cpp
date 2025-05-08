#include "header_files.h"
/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie
{
private:
    vector<Trie*> children;
    bool isEnd;

public:
    Trie() : children(26), isEnd(false)
    {
    }

    void insert(string word)
    {
        Trie* node=this;
        for (auto w : word)
        {
            w -= 'a';
            if (node->children[w] == nullptr)
            {
                node->children[w]=new Trie();
            }
            node=node->children[w];
        }
        node->isEnd=true;
    }

    bool search(string word)
    {
        Trie* node=this;
        for (auto w:word)
        {
            w-='a';
            if (node->children[w]==nullptr)
            {
                return false;
            }
            node=node->children[w];
        }
        
        return node->isEnd;
    }

    bool startsWith(string prefix)
    {
        Trie* node=this;
        for (auto w:prefix)
        {
            w-='a';
            if (node->children[w]==nullptr)
            {
                return false;
            }
            node=node->children[w];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
