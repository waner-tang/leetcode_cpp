#include "header_files.h"
/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
        {
            return nullptr;
        }
        ListNode *slow_head = head;
        ListNode *quick_head = head;
        while (quick_head && quick_head->next)
        {
            slow_head = slow_head->next;
            quick_head = quick_head->next->next;
            if (quick_head == slow_head)
            {
                break;
            }
        }

        if (quick_head == slow_head)
        {
            ListNode *restart = head;
            while (restart != slow_head)
            {
                restart = restart->next;
                slow_head = slow_head->next;
            }
            return restart;
        }
        else
        {
            return nullptr;
        }
        

        // if (!head)
        // {
        //     return nullptr;
        // }
        // unordered_set<ListNode*> re;
        // ListNode* ln=head;
        // re.emplace(ln);
        // while (ln->next)
        // {
        //     if (!re.emplace(ln->next).second)
        //     {
        //         return ln->next;
        //     }
        //     ln=ln->next;
        // }
        // return nullptr;
    }
};
// @lc code=end
