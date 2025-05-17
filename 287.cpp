#include "header_files.h"
/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // 类似于环形链表
        int fast = nums[0], slow = nums[0];
        do
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (fast != slow);
        
        fast = nums[0];
        while (fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }

        return fast;
    }
};
// @lc code=end
