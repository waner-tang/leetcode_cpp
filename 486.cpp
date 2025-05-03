#include"header_files.h"
/*
 * @lc app=leetcode.cn id=486 lang=cpp
 *
 * [486] 预测赢家
 */

// @lc code=start
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        // 构建dp数组
        vector<vector<pair<int,int>>> dp(nums.size(),vector<pair<int,int>>(nums.size()));
        for (int i = 0; i < nums.size(); i++)
        {
            dp[i][i].first=nums[i];
            dp[i][i].second=0;
        }
        // 由于求dp[i][j]需要知道dp[i+1][j]与dp[i][j-1]的情况，故遍历顺序如下
        for (int i = nums.size()-2; i >=0; i--)
        {
            for (int j = i+1; j < nums.size(); j++)
            {
                if (nums[i]+dp[i+1][j].second>nums[j]+dp[i][j-1].second)
                {
                    dp[i][j].first=nums[i]+dp[i+1][j].second;
                    dp[i][j].second=dp[i+1][j].first;
                }
                else
                {
                    dp[i][j].first=nums[j]+dp[i][j-1].second;
                    dp[i][j].second=dp[i][j-1].first;
                }
            }
            
        }
        

        if (dp[0][nums.size()-1].first-dp[0][nums.size()-1].second>=0)
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

