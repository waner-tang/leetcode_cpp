#include"header_files.h"
/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        return recursion(head);
    }
    ListNode* recursion(ListNode* head){
        if (!head||!head->next)
        {
            return head;
        }
        ListNode* h1=head->next;
        head->next=recursion(h1->next);
        h1->next=head;
        return h1;
    }
};
// @lc code=end

