#include"header_files.h"
/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
    // 状态转移方程：
public:
    int jump(vector<int>& nums) {
        return greedy(nums,0,0);
    }
    int greedy(vector<int>& nums,int start,int max_index)
    {
        if (max_index>=nums.size()-1)
        {
            return 0;
        }
        
        int new_max_index=max_index;
        for (int i = start; i <= max_index; i++)
        {
            new_max_index=max(new_max_index,i+nums[i]);
        }
        
        return greedy(nums,max_index+1,new_max_index)+1;
    }
};
// @lc code=end

