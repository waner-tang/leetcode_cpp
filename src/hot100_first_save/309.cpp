#include"header_files.h"
/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    // 状态转移方程：
    // dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i])
    // dp[i][1]=max(dp[i-1][1],dp[i-2][0]-prices[i])
    int maxProfit(vector<int>& prices) {
        int dp0=0,dp1=-prices[0];
        int res=0;
        for (int i = 1; i < prices.size(); i++)
        {
            int res2=dp0;
            dp0=max(dp0,dp1+prices[i]);
            dp1=max(dp1,res-prices[i]);
            res=res2;
        }
        return dp0;
    }
};
// @lc code=end

