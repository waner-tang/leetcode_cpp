#include"header_files.h"
/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int s=nums.size();
        for (int i=0;i<s;i++)
        {
            if (nums[i]<=0)
            {
                nums[i]=s+1;
            }
            
        }
        for (int i=0;i<s;i++)
        {
            if (abs(nums[i])<=s)
            {
                nums[abs(nums[i])-1]=-abs(nums[abs(nums[i])-1]);
            }
            
        }

        for (int i=0;i<s;i++)
        {
            if (nums[i]>0)
            {
                return i+1;
            }
            
        }
        return s+1;
    }
};
// @lc code=end

