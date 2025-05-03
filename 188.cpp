#include "header_files.h"
/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution
{
public:
    // 状态转移方程：
    // dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i])
    // dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i])
    int maxProfit(int k, vector<int> &prices)
    {
        if (k > prices.size() / 2)
        {
            int dp0 = 0;
            int dp1 = -prices[0];
            for (int i = 1; i < prices.size(); i++)
            {
                int res = dp0;
                dp0 = max(dp0, dp1 + prices[i]);
                dp1 = max(dp1, res - prices[i]);
            }
            return dp0;
        }

        vector<vector<vector<int>>> dp(prices.size(),
                                    vector<vector<int>>(k + 1, vector<int>(2)));
        dp[0][0][0] = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (i == 0)
                {
                    dp[0][j][0] = 0;
                    dp[0][j][1] = -prices[0];
                    continue;
                }
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }
        return dp[prices.size() - 1][k][0];
    }
};
// @lc code=end
