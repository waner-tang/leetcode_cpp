#include "header_files.h"
/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
private:
    // vector<TreeNode*> result;
public:
    void flatten(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        root = recursion(root);
        // for (int i = 0; i < result.size()-1; i++)
        // {
        //     result[i]->right=result[i+1];
        //     result[i]->left=nullptr;
        // }
    }
    TreeNode *recursion(TreeNode *root)
    {
        if (!root)
        {
            return nullptr;
        }
        // result.push_back(root);
        TreeNode *l = recursion(root->left);
        TreeNode *r = recursion(root->right);
        root->left = nullptr;
        if (l)
        {
            TreeNode *l_end = l;
            while (l_end && l_end->right)
            {
                l_end = l_end->right;
            }
            l_end->right = r;
            root->right = l;
        }
        else
        {
            root->right=r;
        }
        
        return root;
    }
};
// @lc code=end
