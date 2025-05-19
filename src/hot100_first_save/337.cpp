#include"header_files.h"
/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    unordered_map<TreeNode*,int> memo;
    int rob(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        if (memo.find(root)!=memo.end())
        {
            return memo[root];
        }
        
        int not_do=rob(root->left)+rob(root->right);
        int do_it=root->val;
        if (root->left)
        {
            do_it+=rob(root->left->left)+rob(root->left->right);
        }
        if (root->right)
        {
            do_it+=rob(root->right->left)+rob(root->right->right);
        }
        
        memo[root]=max(not_do,do_it);
        return memo[root];
    }
};
// @lc code=end

