#include"header_files.h"
/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int winner=nums[0];
        int life=1;
        for (int i=1;i<nums.size();i++)
        {
            if (winner!=nums[i]&&life>=1)
            {
                life--;
            }
            else if (winner!=nums[i]&&life==0)
            {
                winner=nums[i];
                life=1;
            }
            else
            {
                life++;
            }
            
        }
        return winner;
    }
};
// @lc code=end

