#include"header_files.h"
/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    // 状态转移方程：max_dp[i]=max(nums[i],max_dp[i-1]*nums[i])  nums[i]>=0
    // max_dp[i]=max(nums[i],min_dp[i-1]*nums[i])    nums[i]<0
    // min_dp[i]=min(nums[i],min_dp[i-1]*nums[i],max_dp[i-1]*nums[i])
    int maxProduct(vector<int>& nums) {
        int curr_max=nums[0];
        int curr_min=nums[0];
        int total_max=curr_max;
        for (int i = 1; i < nums.size(); i++)
        {
            int cm;
            if (nums[i]>=0)
            {
                cm=max(nums[i],curr_max*nums[i]);
            }
            else
            {
                cm=max(nums[i],curr_min*nums[i]);
            }
            curr_min=min(nums[i],curr_min*nums[i]);
            curr_min=min(curr_min,curr_max*nums[i]);
            curr_max=cm;
            total_max=max(curr_max,total_max);
        }
        return total_max;
    }
};
// @lc code=end

