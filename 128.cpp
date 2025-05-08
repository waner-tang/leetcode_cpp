#include"header_files.h"
/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        
        unordered_map<int,bool> corr;
        for (int i = 0; i < nums.size(); i++)
        {
            if (corr.find(nums[i])==corr.end())
            {
                corr.insert({nums[i],false});
            }
            
        }
        int num=1;
        auto it=corr.begin();
        for (; it !=corr.end(); it++)
        {
            if (it->second==true)
            {
                continue;
            }
            it->second=true;
            int left=it->first;
            int right=it->first;
            while (corr.find(left-1)!=corr.end())
            {
                left--;
                corr[left]=true;
            }
            while (corr.find(right+1)!=corr.end())
            {
                right++;
                corr[right]=true;
            }
            num=max(num,right-left+1);
        }
        return num;
    }
};
// @lc code=end

