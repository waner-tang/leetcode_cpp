#include"header_files.h"
/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    int greedy(vector<int>& nums,int start,int max_index)
    {
        int current=max_index;
        for (int i = start; i <= max_index; i++)
        {
            if (nums[i]+i>current)
            {
                current=nums[i]+i;
            }
            
        }
        return current;
    }
    bool canJump(vector<int>& nums) {
        int target=nums.size()-1;
        int max_index=nums[0];
        int start=0;
        while (max_index<target)
        {
            int start1=max_index;
            int max1=greedy(nums,start,max_index);
            if (start1==max1)
            {
                return false;
            }
            
            start=start1;
            max_index=max1;
        }
        
        return true;
    }
};
// @lc code=end

