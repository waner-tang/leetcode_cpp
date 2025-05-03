#include"header_files.h"
/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    unordered_map<int,int> index_in;
public:
    //根左右 左根右
    //
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
        {
            index_in[inorder[i]]=i;
        }
        
        return recursion(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    TreeNode* recursion(vector<int>& preorder,int s1,int e1, vector<int>& inorder,int s2,int e2)
    {
        if (e1<s1)
        {
            return nullptr;
        }
        TreeNode* root=new TreeNode(preorder[s1]);
        int position_root=index_in[preorder[s1]];
        // for (int i = s2; i <= e2; i++)
        // {
        //     if (inorder[i]==preorder[s1])
        //     {
        //         position_root=i;
        //         break;
        //     }
            
        // }
        root->left=recursion(preorder,s1+1,s1+position_root-s2,inorder,s2,position_root-1);
        root->right=recursion(preorder,s1+position_root-s2+1,e1,inorder,position_root+1,e2);
        return root;
    }
};
// @lc code=end

