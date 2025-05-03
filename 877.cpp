#include"header_files.h"
/*
 * @lc app=leetcode.cn id=877 lang=cpp
 *
 * [877] 石子游戏
 */

// @lc code=start
class Solution {
public:
    // 动态转移方程：
    // dp[i][j].first=max(piles[i]+dp[i+1][j].second,piles[j]+dp[i][j-1].second)
    // dp[i][j].second=dp[i+1][j].first  // 先手选择左边
    // or dp[i][j].second=dp[i][j-1].first   // 先手选择右边
    bool stoneGame(vector<int>& piles) {
        // 构建dp数组
        vector<vector<pair<int,int>>> dp(piles.size(),vector<pair<int,int>>(piles.size()));
        for (int i = 0; i < piles.size(); i++)
        {
            dp[i][i].first=piles[i];
            dp[i][i].second=0;
        }
        // 由于求dp[i][j]需要知道dp[i+1][j]与dp[i][j-1]的情况，故遍历顺序如下
        for (int i = piles.size()-2; i >=0; i--)
        {
            for (int j = i+1; j < piles.size(); j++)
            {
                if (piles[i]+dp[i+1][j].second>piles[j]+dp[i][j-1].second)
                {
                    dp[i][j].first=piles[i]+dp[i+1][j].second;
                    dp[i][j].second=dp[i+1][j].first;
                }
                else
                {
                    dp[i][j].first=piles[j]+dp[i][j-1].second;
                    dp[i][j].second=dp[i][j-1].first;
                }
            }
            
        }
        

        if (dp[0][piles.size()-1].first-dp[0][piles.size()-1].second>0)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};
// @lc code=end

