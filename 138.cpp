#include "header_files.h"
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
        {
            return nullptr;
        }

        unordered_map<Node*,Node*> list;
        Node * curr=head;
        while (curr)
        {
            Node* new_node=new Node(curr->val);
            list[curr]=new_node;
            curr=curr->next;
        }
        curr=head;
        while (curr)
        {
            list[curr]->next=list[curr->next];
            list[curr]->random=list[curr->random];
            curr=curr->next;
        }
        return list[head];
    }
};
// @lc code=end
