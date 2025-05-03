#include "header_files.h"
/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
class Solution
{
public:
    int max_length;// 记录最大节点数量
    int diameterOfBinaryTree(TreeNode *root)
    {
        max_length = 0;
        int i=depth(root);
        return max_length - 1;
    }
    int depth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int l = depth(root->left);
        int r = depth(root->right);
        max_length = max(max_length, l + r + 1);
        return max(l, r) + 1;
    }
};
// @lc code=end
