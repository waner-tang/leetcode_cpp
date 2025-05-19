#include"header_files.h"
/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第 K 小的元素
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
    // 中序遍历（左->根->右）结果必为升序序列
    // vector<int> visited;
    // int kthSmallest(TreeNode* root, int k) {
    //     recursion(root);
    //     return visited[k-1];
    // }
    // void recursion(TreeNode* root)
    // {
    //     if (root&&!root->left&&!root->right)
    //     {
    //         visited.push_back(root->val);
    //         return ;
    //     }
    //     if (root->left)
    //     {
    //         recursion(root->left);
    //     }
    //     visited.push_back(root->val);
    //     if (root->right)
    //     {
    //         recursion(root->right);
    //     }

    //     return ;
    // }

    //  避免多余递归并节省空间
    int count;
    int result;
    int kthSmallest(TreeNode* root, int k) {
        count=0;
        recursion(root,k);
        return result;
    }
    void recursion(TreeNode* root, int k){
        if (!root)
        {
            return ;
        }
        recursion(root->left,k);
        count++;
        if (k==count)
        {
            result=root->val;
            return;
        }
        recursion(root->right,k);
    }
};
// @lc code=end

