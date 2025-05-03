#include"header_files.h"
/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    // 状态转移方程：
    // dp[i][0]=max(dp[i][0],dp[i][1]+prices[i])
    // dp[i][1]=max(dp[i][1],dp[i][0]-prices[i])
    int maxProfit(vector<int>& prices) {
        // // 传统
        // vector<vector<int>> dp(prices.size(),vector<int>(2));
        // dp[0][0]=0;
        // dp[0][1]=-prices[0];
        // for (int i = 1; i < prices.size(); i++)
        // {
        //     dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
        //     dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
        // }
        // return dp[prices.size()-1][0];

        // 节省运算空间
        int dp0=0;
        int dp1=-prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            int res=dp0;
            dp0=max(dp0,dp1+prices[i]);
            dp1=max(dp1,res-prices[i]);
        }
        return dp0;
    }
};
// @lc code=end

