#include"header_files.h"
/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    TreeNode* invertTree(TreeNode* root) {
        reverse(root);
        return root;
    }
    void reverse(TreeNode* root)
    {
        if (!root)
        {
            return;
        }
        
        TreeNode* transfer_node;
        transfer_node=root->left;
        root->left=root->right;
        root->right=transfer_node;
        // if (transfer_node)
        // {
        //     delete transfer_node;
        // }
        reverse(root->left);
        reverse(root->right);
    }
};
// @lc code=end

