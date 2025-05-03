#include "header_files.h"
/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
            // 传统解法
            if (!head||k==1)
            {
                return head;
            }

            ListNode* begin=head;
            ListNode* last=head;
            vector<pair<ListNode*, ListNode*>> subnode;
            int num=0;
            while (last)
            {
                num++;
                last=last->next;
                if (num==k)
                {
                    ListNode* new_begin=last;
                    subnode.push_back(reverseNode(begin,k));
                    num=0;
                    begin=new_begin;
                    last=new_begin;
                }
            }

            if (num!=0)
            {
                subnode.push_back(make_pair(begin,last));
            }

            for (int i = 0; i < subnode.size()-1; i++)
            {
                subnode[i].second->next=subnode[i+1].first;
            }
            return subnode[0].first;
        }
        pair<ListNode*, ListNode*> reverseNode(ListNode* begin, int k)
        {
            ListNode* ne=begin;
            ListNode* curr=nullptr;
            while (k--)
            {
                ListNode* new_ne=ne->next;
                ne->next=curr;
                curr=ne;
                ne=new_ne;
            }
            return {curr,begin};

        }
};
// @lc code=end
