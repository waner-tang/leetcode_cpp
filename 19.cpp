#include"header_files.h"
/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    // 快慢指针
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next)
        {
            return nullptr;
        }
        if (head->next&&!head->next->next)
        {
            if (n==1)
            {
                head->next=nullptr;
                
            }
            else
            {
                head=head->next;
            }
            return head;
        }
        if (head->next&&head->next->next&&!head->next->next->next)
        {
            if (n==1)
            {
                head->next->next=nullptr;
                
            }
            else if (n==2)
            {
                head->next=head->next->next;
            }
            else
            {
                head=head->next;
            }
            return head;
        }
        
        
        
        ListNode* head_slow=head;
        ListNode* head_fast=head;
        for (int i = 2; i <= n; i++)
        {
            head_fast=head_fast->next;
        }
        
        if (head_fast->next==nullptr)
        {
            head=head->next;
            return head;
        }
        
        
        while (head_fast->next&&head_fast->next->next)
        {
            
            head_fast=head_fast->next;
            head_slow=head_slow->next;
        }
        head_slow->next=head_slow->next->next;
        
        return head;
    }
};
// @lc code=end

