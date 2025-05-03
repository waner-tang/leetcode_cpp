#include"header_files.h"
/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1&&!list2)
        {
            return nullptr;
        }
        if (!list1)
        {            
            return list2;
        }
        if (!list2)
        {            
            return list1;
        }
        ListNode* start2;
        if (list1->val<list2->val)
        {
            start2=list1;
            recursion(list1->next,list2,start2->next);
        }
        else
        {
            start2=list2;
            recursion(list1,list2->next,start2->next);
        }
        return start2;
    }
    void recursion(ListNode* list1, ListNode* list2,ListNode*& start)
    {
        if (!list1&&!list2)
        {
            start=nullptr;
            return ;
        }
        if (!list1)
        {
            start=list2;
            return;
        }
        if (!list2)
        {
            start=list1;
            return;
        }

        if (list1->val<list2->val)
        {
            start=list1;
            recursion(list1->next,list2,start->next);
        }
        else
        {
            start=list2;
            recursion(list1,list2->next,start->next);
        }
        return;
    }
};
// @lc code=end

