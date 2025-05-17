#include"header_files.h"
/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        int min_num=nums[0];
        while (left<=right)
        {
            int middle=(left+right)/2;
            if (nums[middle]>nums[left]&&nums[middle]>nums[right])
            {
                min_num=min(min_num,nums[left]);
                left=middle+1;
            }
            else if (nums[middle]<nums[left]&&nums[middle]<nums[right])
            {
                min_num=min(min_num,nums[middle]);
                right=middle-1;
            }
            else if (nums[middle]>=nums[left]&&nums[middle]<nums[right])
            {
                min_num=min(min_num,nums[left]);
                break;
            }
            else
            {
                min_num=min(min_num,nums[right]);
                break;
            }
            
        }
        return min_num;
    }
};
// @lc code=end

