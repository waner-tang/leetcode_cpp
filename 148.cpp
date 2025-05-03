#include"header_files.h"
/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        // if(!head)
        // {
        //     return nullptr;
        // }

        // vector<ListNode*> list;
        // ListNode* curr=head;
        // while (curr)
        // {
        //     list.push_back(curr);
        //     curr=curr->next;
        // }
        // sort(list.begin(),list.end(),[](const ListNode* a, const ListNode* b){
        //     return a->val<b->val;
        // });
        // for (int i = 0; i < list.size(); i++)
        // {
        //     if (i==list.size()-1)
        //     {
        //         list[i]->next=nullptr;
        //     }
        //     else
        //     {
        //         list[i]->next=list[i+1];
        //     }
            
        // }
        // return list[0];

        // 链表归并归并排序
        if(!head||!head->next)
        {
            return head;
        }

        // 快慢指针找到链表中点
        ListNode * slow_head=head;
        ListNode * fast_head=head->next;
        while (fast_head&&fast_head->next)
        {
            slow_head=slow_head->next;
            fast_head=fast_head->next->next;
        }
        // 分成两段并断开
        ListNode * mid_head=slow_head->next;
        slow_head->next=nullptr;

        ListNode * left=sortList(head);
        ListNode * right=sortList(mid_head);

        return merge(left,right);

    }
    ListNode * merge(ListNode * left, ListNode * right)
    {
        ListNode dummy;
        ListNode * tail=& dummy;
        while (left&&right)
        {
            if (left->val<right->val)
            {
                tail->next=left;
                left=left->next;
            }
            else
            {
                tail->next=right;
                right=right->next;
            }
            tail=tail->next;
        }
        tail->next= left? left:right;
        return dummy.next;
    }
};
// @lc code=end

