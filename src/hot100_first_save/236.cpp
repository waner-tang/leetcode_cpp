#include"header_files.h"
/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP;
        vector<TreeNode*> pathQ;
        traceback(root,p,pathP);
        traceback(root,q,pathQ);
        int m=pathP.size()-1;
        int n=pathQ.size()-1;
        while (m>=0&&n>=0)
        {
            if (pathP[m]!=pathQ[n])
            {
                break;
            }
            m--;
            n--;
        }
        if (m==-1||n==-1)
        {
            return m==-1? p:q;
        }
        else
        {
            return pathP[m+1];
        }
        
    }
    bool traceback(TreeNode* root, TreeNode* t,vector<TreeNode*>& path){
        if (!root)
        {
            return false;
        }
        if (root==t)
        {
            path.push_back(root);
            return true;
        }
        
        if (traceback(root->left,t,path))
        {
            path.push_back(root);
            return true;
        }
        else if (traceback(root->right,t,path))
        {
            path.push_back(root);
            return true;
        }
        return false;
    }
};
// @lc code=end

