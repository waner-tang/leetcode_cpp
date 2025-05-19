#include"header_files.h"
/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        vector<int> ans(2, -1);
        while (left <= right) {
            int middle = (left + right) / 2;
            if (nums[middle] == target) {
                ans[0] = middle;
                ans[1] = middle;
                break;
            } else if (nums[middle] > target) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        if (ans[0] == -1) {
            return ans;
        }
        while (ans[0] - 1 >= 0 && nums[ans[0] - 1] == target) {
            ans[0]--;
        }
        while (ans[1] + 1 < nums.size() && nums[ans[1] + 1] == target) {
            ans[1]++;
        }
        return ans;

        // 常规写法，下面直接找target-0.5与target+0.5
    }
};
// @lc code=end

