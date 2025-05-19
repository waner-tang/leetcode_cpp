#include"header_files.h"
/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> v_left;
        int l_index=0;
        v_left.push_back(-1);
        for (int i = 1; i < height.size(); i++)
        {
            if (height[l_index]>height[i])
            {
                v_left.push_back(l_index);
                continue;
            }
            l_index=i;
            v_left.push_back(-1);
            
        }
        int ans=0;
        int r_index=height.size()-1;
        for (int i = height.size()-2; i >=0; i--)
        {
            if (height[r_index]>height[i]&&v_left[i]!=-1)
            {
                ans+=min(height[r_index],height[v_left[i]])-height[i];
            }
            else if (height[r_index]<height[i])
            {
                r_index=i;
            }
            
            
        }

        return ans;
    }
};
// @lc code=end

