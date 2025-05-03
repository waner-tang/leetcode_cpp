#include"header_files.h"
/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // unordered_set<ListNode*> toFind;
        // ListNode *temp=headA;
        // while (temp)
        // {
        //     toFind.insert(temp);
        //     temp=temp->next;
        // }
        // temp=headB;
        // while (temp)
        // {
        //     if (toFind.find(temp)!=toFind.end())
        //     {
        //         return temp;
        //     }
        //     temp=temp->next;
        // }
        // return nullptr;

        // 非常规方法
        ListNode * a=headA;
        ListNode * b=headB;
        while (a!=b)
        {
            a= a!=nullptr ? a->next :headB;
            b= b!=nullptr ? b->next :headA;
        }
        return a;
    }
};
// @lc code=end

