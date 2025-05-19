#include"header_files.h"
/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
    // dp[i] 表示以 nums[i] 这个数结尾的最长递增子序列的长度
    // 状态转移方程：dp[i]=max(dp[j],...)+1  (0<=j<i&&nums[i]>nums[j])
public:
    // // 动态规划解法
    // int lengthOfLIS(vector<int>& nums) {
    //     vector<int> dp(nums.size());
    //     dp[0]=1;
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         int res=1;
    //         for (int j = 0; j < i; j++)
    //         {
    //             if (nums[i]>nums[j])
    //             {
    //                 res=max(res,dp[j]+1);
    //             }
    //         }
    //         dp[i]=res;
    //     }
        
    //     int res=1;
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         res=max(res,dp[i]);
    //     }
        
    //     return res;
    // }

    // 二分查找+贪心算法
    int lengthOfLIS(vector<int>& nums) {
        vector<int> top;
        top.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            int left=0;
            int right=top.size()-1;
            while (left<right)
            {
                int mid=(left+right)/2;
                if (nums[i]<top[mid])
                {
                    right=mid;
                }
                else if (nums[i]>top[mid])
                {
                    left=mid+1;   //当left right  分别为1 2 时，不+1会陷入死循环
                }
                else
                {
                    right=mid;
                }
            }
            
            if (left==top.size()-1&&nums[i] > top[left])
            {
                top.push_back(nums[i]);  // 新建堆
            }
            else
            {
                top[left]=nums[i];
            }
            
        }
        
        return top.size();
    }
};
// @lc code=end

