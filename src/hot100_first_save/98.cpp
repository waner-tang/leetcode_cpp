#include"header_files.h"
/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    // 注意必须是左子树所有值小于当前节点值，右子树所有值大于当前节点值
    bool isValidBST(TreeNode* root) {
        return recursion(root,INT_MIN,INT_MAX,false ,false );
    }
    bool recursion(TreeNode* root,int min_num,int max_num,bool l,bool r)
    {
        if (!root)
        {
            return true;
        }
        bool flag1;
        bool flag2;
        if (!l&&!r)
        {
            flag1=recursion(root->left,min_num,root->val,false,true);
            flag2=recursion(root->right,root->val,max_num,true,false);
        }
        else if (!l)
        {
            flag1=(root->val<max_num&&recursion(root->left,min_num,root->val,false,true));
            flag2=(root->val<max_num&&recursion(root->right,root->val,max_num,true,true));
        }
        else if (!r)
        {
            flag1=(root->val>min_num&&recursion(root->left,min_num,root->val,true,true));
            flag2=(root->val>min_num&&recursion(root->right,root->val,max_num,true,false));
        }
        else
        {
            flag1=(root->val>min_num&&root->val<max_num&&recursion(root->left,min_num,root->val,true,true));
            flag2=(root->val>min_num&&root->val<max_num&&recursion(root->right,root->val,max_num,true,true));
        }
        return flag1&&flag2;
    }
};
// @lc code=end

