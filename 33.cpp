#include "header_files.h"
/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left<=right)
        {
            int middle=(left+right)/2;
            if (nums[middle]==target)
            {
                return middle;
            }
            if(nums[left]==target)
            {
                return left;
            }
            if (nums[right]==target)
            {
                return right;
            }
            
            if (nums[middle]>nums[left]&&nums[middle]>nums[right])
            {
                if (nums[left]<target&&nums[middle]>target)
                {
                    right=middle-1;
                }
                else
                {
                    left=middle+1;
                }
                
            }
            else if(nums[middle]<nums[left]&&nums[middle]<nums[right])
            {
                if (nums[middle]<target&&nums[right]>target)
                {
                    left=middle+1;
                }
                else
                {
                    right=middle-1;
                }
            }
            else if (nums[middle]>nums[left]&&nums[middle]<nums[right])
            {
                if (nums[middle]>target)
                {
                    right=middle-1;
                }
                else
                {
                    left=middle+1;
                }
                
            }
            else
            {
                if (nums[middle]>target)
                {
                    left=middle+1;
                }
                else
                {
                    right=middle-1;
                }
            }
            
        }
        return -1;

    }
};
// @lc code=end
