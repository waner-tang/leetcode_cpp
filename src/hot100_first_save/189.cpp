#include"header_files.h"
/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // k=k%nums.size();
        // while (k>0)
        // {
        //     int num=nums.back();
        //     nums.pop_back();
        //     nums.insert(nums.begin(),num);// 时间复杂度O(n),大量操作尽量避免
        //     k--;
        // }
        k=k%nums.size();
        if (k==0)
        {
            return;
        }
        
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
// @lc code=end

