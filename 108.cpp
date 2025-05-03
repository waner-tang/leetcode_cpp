#include"header_files.h"
/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return binary(nums,0,nums.size()-1);

    }
    TreeNode * binary(vector<int>& nums,int start, int end)
    {
        if (start>end)
        {
            return nullptr;
        }
        TreeNode* node=new TreeNode();
        if (start==end)
        {
            node->val=nums[start];
            return node;
        }
        
        int mid=(start+end)/2;
        node->val=nums[mid];
        node->left=binary(nums,start,mid-1);
        node->right=binary(nums,mid+1,end);
        return node;
    }
};
// @lc code=end

