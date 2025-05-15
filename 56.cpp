#include"header_files.h"
/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto& a ,auto& b){
            return a[0]<b[0];
        });

        vector<vector<int>> ans;
        int start=intervals[0][0],end=intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0]<=end)
            {
                end=max(end,intervals[i][1]);
            }
            else
            {
                ans.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
                
            }
            
        }
        ans.push_back({start,end});

        return ans;
    }
};
// @lc code=end

