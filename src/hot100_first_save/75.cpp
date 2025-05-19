#include"header_files.h"
/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int middle=0;
        while (middle<=high)
        {
            if (nums[middle]==0)
            {
                swap(nums[middle],nums[low]);
                middle++;
                low++;
            }
            else if (nums[middle]==2)
            {
                swap(nums[middle],nums[high]);
                high--;
            }
            else
            {
                middle++;
            }
            
        }
        
    }
};
// @lc code=end

