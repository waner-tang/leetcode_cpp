#include"header_files.h"
/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        if (!root)
        {
            return true;
        }
        return reverse(root->left,root->right);
    }
    bool reverse(TreeNode* root1, TreeNode* root2)
    {
        if ((root1&&!root2)||(!root1&&root2))
        {
            return false;
        }
        
        if (!root1&&!root2)
        {
            return true;
        }
        
        if (root1->val==root2->val)
        {
            return reverse(root1->left,root2->right)&&reverse(root2->left,root1->right);
        }
        
        return false;
    }
};
// @lc code=end

