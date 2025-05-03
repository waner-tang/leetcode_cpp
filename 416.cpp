#include"header_files.h"
/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    // 状态转移方程：dp(i)=dp(i)||dp(i-num)
    vector<vector<int>> memo;
    bool canPartition(vector<int>& nums) {
        int count=0;
        for (auto num:nums)
        {
            count+=num;
        }
        if (count%2!=0)
        {
            return false;
        }
        memo.assign(count/2+1,vector<int>(nums.size(),-1));
        return dp(count/2,nums,0);
    }
    bool dp(int target,vector<int>& nums,int start)
    {
        if (target==0)
        {
            return true;
        }
        if (start==nums.size())
        {
            return false;
        }
        
        if (memo[target][start]!=-1)
        {
            return memo[target][start];
        }
        
        bool flag=false;
        for (int i = start; i < nums.size(); i++)
        {
            if (target-nums[i]>=0&&dp(target-nums[i],nums,i+1))
            {
                flag=true;
                break;
            }
            
        }
        memo[target][start]=flag;
        return flag;
    }
};
// @lc code=end

