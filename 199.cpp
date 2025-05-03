#include"header_files.h"
/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> result;
    int num;
public:
    vector<int> rightSideView(TreeNode* root) {
        num=0;
        recursion(root,1);
        return result;
    }
    void recursion(TreeNode* root,int h){
        if (!root)
        {
            return;
        }
        if (h>num)
        {
            result.push_back(root->val);
            num++;
        }
        recursion(root->right,h+1);
        recursion(root->left,h+1);
        return;
    }
};
// @lc code=end

