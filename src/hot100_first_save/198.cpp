#include"header_files.h"
/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    // 状态转移方程：dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
    int rob(vector<int>& nums) {
        // if (nums.size()==1)
        // {
        //     return nums[0];
        // }
        
        // vector<int> dp(nums.size()+2);
        // dp[nums.size()-1]=nums[nums.size()-1];
        // dp[nums.size()]=0;
        // for (int i = nums.size()-2; i >=0 ; i--)
        // {
        //     dp[i]=max(dp[i+1],dp[i+2]+nums[i]);
        // }
        
        // return dp[0];

        // 节省运算空间
        if (nums.size()==1)
        {
            return nums[0];
        }
        int dp1=nums[nums.size()-1];
        int dp2=0;
        int dp;
        for (int i = nums.size()-2; i >=0 ; i--)
        {
            dp=max(dp1,dp2+nums[i]);
            
            dp2=dp1;
            dp1=dp;
        }
        return dp;
    }

    
};
// @lc code=end

