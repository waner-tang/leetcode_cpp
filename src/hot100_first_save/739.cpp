#include "header_files.h"
/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> ans(temperatures.size(), 0);
        stack<int> tem;
        for (int i = temperatures.size() - 1; i >= 0; i--)
        {
            while (!tem.empty() && temperatures[tem.top()]<= temperatures[i])
            {
                tem.pop();
            }

            if (tem.empty())
            {
                tem.push(i);
            }
            else
            {
                ans[i] = tem.top()- i;
                tem.push(i);
            }
        }
        return ans;
    }
};
// @lc code=end
