#include"header_files.h"
/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
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
    int sum;
    // 当前结点 min max 
    void traverse(TreeNode* root, int low, int high)
    {
        if (!root)
        {
            return;
        }
        
        if (root->val>=low&&root->val<=high)
        {
            sum+=root->val;
        }
        
        traverse(root->left,low,high);

        traverse(root->right,low,high);
        
        
        
        
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum=0;
        traverse(root, low, high);
        return sum;
    }
};
// @lc code=end

