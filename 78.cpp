#include "header_files.h"
/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution
{
public:
    // 总结果，目前结果，原数组， 要求数量, 当前初始遍历数组的位置
    void backtrack(vector<vector<int>> &result, vector<int> &current, vector<int> &nums, int n, int position)
    {
        if (current.size()==n)   //结束条件
        {
            result.push_back(current);
            return;
        }
        
        for (int i = position; i < nums.size(); i++)
        {
            if (find(current.begin(),current.end(),nums[i])==current.end())
            {
                current.push_back(nums[i]);   //做选择
                backtrack(result,current,nums,n,i+1);
                current.pop_back();    //撤销选择
            }
            
        }
        
        
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> current;
        for (int i = 0; i <= nums.size(); i++)
        {
            backtrack(result,current,nums,i,0);
        }
        
        return result;
    }
};
// @lc code=end
