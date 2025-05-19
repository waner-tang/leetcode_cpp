#include"header_files.h"
/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> traverse;
        vector<vector<int>> results;
        if (root)
        {
            traverse.push(root);
        }
        while (!traverse.empty())
        {
            vector<int> nums;
            int size=traverse.size();
            for (int i = size; i >0; i--)
            {
                nums.push_back(traverse.front()->val);
                if (traverse.front()->left)
                {
                    traverse.push(traverse.front()->left);
                }
                if (traverse.front()->right)
                {
                    traverse.push(traverse.front()->right);
                }
                traverse.pop();
  
            }
            results.push_back(nums);
        }

        reverse(results.begin(),results.end());

        return results;
        
    }
};
// @lc code=end

