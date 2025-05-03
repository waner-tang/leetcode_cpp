#include"header_files.h"
/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        if (!head)
        {
            return true;
        }
        
        vector<int> nums;
        ListNode* temp=head;
        while (temp)
        {
            nums.push_back(temp->val);
            temp=temp->next;
        }
        int i=0;
        int j=nums.size()-1;
        while (i<j)
        {
            if (nums[i]==nums[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
            
            
        }
        return true;
    }
};
// @lc code=end

