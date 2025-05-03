#include"header_files.h"
/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    // 状态转移方程：
    // dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i])
    // dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]-fee)
    int maxProfit(vector<int>& prices, int fee) {
        int dp0=0,dp1=-prices[0]-fee;
        for (int i = 1; i < prices.size(); i++)
        {
            int res=dp0;
            dp0=max(dp0,dp1+prices[i]);
            dp1=max(dp1,dp0-prices[i]-fee);
        }
        return dp0;
    }
};
// @lc code=end

