#include"header_files.h"
/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> curr;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!curr.empty()&&i-curr.front()>=k)
            {
                curr.pop_front();   //超出服务年限，再厉害都裁
            }
            
            while (!curr.empty()&&nums[curr.back()]<nums[i])
            {
                curr.pop_back();    //没新来的厉害，裁
            }
            
            curr.emplace_back(i);
            if (i>=k-1)
            {
                ans.push_back(nums[curr.front()]);
            }
            
        }
        return ans;
    }
};
// @lc code=end

