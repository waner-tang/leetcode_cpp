#include"header_files.h"
/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
private:
    int sum;
public:
    int maxPathSum(TreeNode* root) {
        sum=INT_MIN;
        dfs(root);
        return sum;
    }
    int dfs(TreeNode* root){
        if (!root)
        {
            return 0;
        }
        
        int sumMax=0;
        int l=dfs(root->left);
        int r=dfs(root->right);
        sumMax=max(l+root->val,r+root->val);
        sumMax=max(sumMax,root->val);
        sum=max(sumMax,sum);
        sum=max(sum,l+r+root->val);
        return sumMax;
    }
};
// @lc code=end

