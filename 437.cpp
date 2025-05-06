#include "header_files.h"
/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return 0;
        }
        
        int num=0;
        num=traceback(root, targetSum);
        num+=pathSum(root->left,targetSum);
        num+=pathSum(root->right,targetSum);
        return num;
    }
    int traceback(TreeNode *root, long targetSum)
    {
        if (!root)
        {
            return 0;
        }
        
        int num=0;
        if (targetSum==root->val)
        {
            num++;
        }

        num+=traceback(root->left, targetSum-root->val);
        num+=traceback(root->right, targetSum-root->val);
        return num;
    }
};
// @lc code=end
