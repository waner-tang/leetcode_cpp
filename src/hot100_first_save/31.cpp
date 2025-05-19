#include"header_files.h"
/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size()==1)
        {
            return;
        }
        
        int start=-1;
        for (int i = nums.size()-1; i >=1; i--)
        {
            if (nums[i]>nums[i-1])
            {
                start=i-1;
                break;
            }            
        }
        if (start==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        
        int tochange=-1;
        for (int i = start+1; i < nums.size(); i++)
        {
            if (nums[i]<=nums[start])
            {
                break;
            }
            tochange=i;
        }
        swap(nums[tochange],nums[start]);
        reverse(nums.begin()+start+1,nums.end());
    }
};
// @lc code=end

