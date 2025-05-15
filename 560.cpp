#include"header_files.h"
/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> pre;
        int total=0,ans=0;
        for (int i = 0; i < nums.size(); i++)
        {
            total+=nums[i];
            if (pre.find(total-k)!=pre.end())
            {
                ans+=pre[total-k];
            }
            
            if (total==k)
            {
                ans++;
            }
            
            if (pre.find(total)!=pre.end())
            {
                pre[total]++;
            }
            else
            {
                pre.insert({total,1});
            }
        }
        return ans;
    }
};
// @lc code=end

