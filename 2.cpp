#include"header_files.h"
/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* start=new ListNode();
        recursion(l1,l2,start,0);
        return start;
    }
    void recursion(ListNode* l1, ListNode* l2,ListNode*& start,int is_1)
    {
        if (!l1&&!l2)
        {
            if (is_1==1)
            {
                start->val=1;
            }
            else
            {
                start=nullptr;
            }
            
            return;
        }
        start->next=new ListNode();
        if (!l1)
        {
            if (is_1==1)
            {
                int sum=l2->val+1;
                if (sum<10)
                {
                    start->val=sum;
                    start->next=l2->next;
                    is_1=0;
                    return;
                }
                else
                {
                    start->val=sum%10;
                    is_1=1;
                    recursion(l1,l2->next,start->next,is_1);
                    return;
                }
                
            }
            else
            {
                start=l2;
                return;
            }
            
        }
        

        if (!l2)
        {
            if (is_1==1)
            {
                int sum=l1->val+1;
                if (sum<10)
                {
                    start->val=sum;
                    start->next=l1->next;
                    is_1=0;
                    return;
                }
                else
                {
                    start->val=sum%10;
                    is_1=1;
                    recursion(l1->next,l2,start->next,is_1);
                    return;
                }
                
            }
            else
            {
                start=l1;
                return;
            }
            
        }
        
        if (is_1+l1->val+l2->val<10)
        {
            start->val=is_1+l1->val+l2->val;
            is_1=0;
        }
        else
        {
            start->val=(is_1+l1->val+l2->val)%10;
            is_1=1;
        }
        recursion(l1->next,l2->next,start->next,is_1);
        return;
    }
};
// @lc code=end

