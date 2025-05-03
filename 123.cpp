#include "header_files.h"
/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution
{
public:
    // 状态转移方程：
    // dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i])
    // dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i])
    int maxProfit(vector<int> &prices)
    {
        // // 传统
        // vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(3, vector<int>(2)));
        // dp[0][0][0]=0;
        // dp[0][1][1]=-prices[0];
        // for (int i = 0; i < prices.size(); i++)
        // {
        //     for (int j = 1; j <= 2; j++)
        //     {
        //         if (i == 0)
        //         {
        //             dp[i][j][0] = 0;
        //             dp[i][j][1] = -prices[0];
        //             continue;
        //         }
        //         dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
        //         dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
        //     }
        // }
        // return dp[prices.size() - 1][2][0];

        // 节省计算空间
        // 状态转移方程：
        // dp[i][2][0] = max(dp[i-1][2][0], dp[i-1][2][1] + prices[i])
        // dp[i][2][1] = max(dp[i-1][2][1], dp[i-1][1][0] - prices[i])
        // dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i])
        // dp[i][1][1] = max(dp[i-1][1][1], -prices[i])
        int dp_10=0,dp_11=-prices[0];
        int dp_20=0,dp_21=-prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            int res=dp_10;
            dp_10=max(dp_10,dp_11+prices[i]);
            dp_11=max(dp_11,-prices[i]);
            dp_20=max(dp_20,dp_21+prices[i]);
            dp_21=max(dp_21,res-prices[i]);
        }
        return dp_20;
    }
};
// @lc code=end
