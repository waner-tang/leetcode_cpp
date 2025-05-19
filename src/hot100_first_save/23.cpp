#include "header_files.h"
/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    // {
    //     return compare(lists);
    // }
    // ListNode* compare(vector<ListNode*>& lists)
    // {
    //     ListNode* head=new ListNode();
    //     int min_num=INT_MAX;
    //     int po=-1;
    //     for (int i=0;i<lists.size();i++)
    //     {
    //         if (lists[i]&&min_num>lists[i]->val)
    //         {
    //             po=i;
    //             min_num=lists[i]->val;
    //         }

    //     }
    //     if (po!=-1)
    //     {
    //         head->next=lists[po];
    //         lists[po]=lists[po]->next;
    //     }
    //     else
    //     {
    //         return nullptr;
    //     }

    //     head->next->next=compare(lists);

    //     return head->next;
    // }
    {
        auto cmp = [](const ListNode *n1, const ListNode *n2) {
            return n1->val>n2->val;// 小值优先
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> q(cmp);

        for (auto list:lists)
        {
            while (list)
            {
                q.push(list);
                list=list->next;
            }
            
        }
        ListNode  dummy;
        ListNode * start= & dummy;
        while (!q.empty())
        {
            start->next=q.top();
            q.pop();
            start=start->next;
            start->next=nullptr;  // 断尾处理
        }
        return dummy.next;
    }
};
// @lc code=end
