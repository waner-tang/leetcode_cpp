#include"header_files.h"
/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=0,e=height.size()-1;
        int area=0;
        while (s<e)
        {
            area=max(min(height[s],height[e])*(e-s),area);
            if (height[s]<height[e])
            {
                s++;
            }
            else
            {
                e--;
            }
        }
        return area;
    }
};
// @lc code=end

