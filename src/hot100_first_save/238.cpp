#include"header_files.h"
/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // vector<int> ans0(nums.size(),1);
        // vector<int> ans1(nums.size(),1);
        // ans0[1]=nums[0];
        // for (int i = 2; i < nums.size(); i++)
        // {
        //     ans0[i]=ans0[i-1]*nums[i-1];
        // }
        // ans1[nums.size()-2]=nums[nums.size()-1];
        // for (int i = nums.size()-3; i >=0; i--)
        // {
        //     ans1[i]=ans1[i+1]*nums[i+1];
        // }
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     ans0[i]=ans0[i]*ans1[i];
        // }
        // return ans0;

        vector<int> ans0(nums.size(),1);
        ans0[1]=nums[0];
        for (int i = 2; i < nums.size(); i++)
        {
            ans0[i]=ans0[i-1]*nums[i-1];
        }
        int res=nums[nums.size()-1];
        for (int i = nums.size()-2; i >=0; i--)
        {
            ans0[i]=ans0[i]*res;
            res=res*nums[i];
        }
        return ans0;
    }
};
// @lc code=end

