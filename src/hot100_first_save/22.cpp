#include"header_files.h"
/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    string instantresult;
    vector<string> result;
    void backtrack(int n,int l,int r)
    {
        // 结束条件：字符串长度满足要求
        if (instantresult.size()==2*n)
        {
            result.push_back(instantresult);
            //移除 instantresult.clear()，路径的维护应通过回溯的 push 和 pop 完成
            // instantresult.clear(); 
            return;
        }

        // 选择1：添加左括号（若左括号数量未达上限）
        if (l<n)
        {
            instantresult.push_back('(');
            //修改局部变量 l 和 r 再传递参数，这可能导致逻辑混乱。更简洁的方式是直接传递 l+1 和 r+1，避免修改当前层的变量
            //l++;    //做选择
            backtrack(n,l+1,r);
            instantresult.pop_back();  //撤销选择
            //移除冗余的 l++ 和 l-- 操作，直接通过参数传递状态
            //l--;
        }

        // 选择2：添加右括号（若右括号数量小于左括号）
        if (r<l)
        {
            instantresult.push_back(')');
            //r++;     //做选择
            //回溯中传递下一层状态时，应直接计算新值（如 l+1），不要修改当前层的变量
            backtrack(n,l,r+1);
            instantresult.pop_back();
            //r--;   //撤销选择
        }
        
        
        
    }
    vector<string> generateParenthesis(int n) {
        backtrack(n,0,0);
        return result;
    }
};
// @lc code=end

