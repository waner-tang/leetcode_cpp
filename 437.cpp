#include"header_files.h"
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
class Solution {//.tangwaner  12334654551
private:
    unordered_map<long, int> prefix;
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return 0;
        }
        prefix[0]=1;
        return traceback(root,targetSum,0);
    }
    int traceback(TreeNode* root, int targetSum, long curr) {
        if (!root) {
            return 0;
        }
        int ans = 0;

        curr += root->val;
        if (prefix.find(curr - targetSum) != prefix.end()) {
            ans = prefix[curr - targetSum];
        }
        prefix[curr]++;
        ans+=traceback(root->left,targetSum,curr);
        ans+=traceback(root->right,targetSum,curr);
        prefix[curr]--;
        return ans;
    }
};
// @lc code=end

