#include"header_files.h"
/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    // 状态转移方程：dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
    // 关键在于做两次dp，取二者最大值，两次包含的数组范围为0---size-2/1---size-1
    int rob(vector<int>& nums) {
        // 节省运算空间
        if (nums.size()==1)
        {
            return nums[0];
        }
        if (nums.size()==2)
        {
            return max(nums[0],nums[1]);
        }
        
        int dp1=nums[nums.size()-1];
        int dp2=0;
        int dp;
        for (int i = nums.size()-2; i >=1 ; i--)
        {
            dp=max(dp1,dp2+nums[i]);
            
            dp2=dp1;
            dp1=dp;
        }

        int dp11=nums[nums.size()-2];
        int dp22=0;
        int dp3;
        for (int i = nums.size()-3; i >=0 ; i--)
        {
            dp3=max(dp11,dp22+nums[i]);
            
            dp22=dp11;
            dp11=dp3;
        }

        return max(dp,dp3);
    }
};
// @lc code=end

