#include"header_files.h"
/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            return a[1]<b[1];
        });
        queue<vector<int>> waiting_process;
        for (auto& interval : intervals) {
            waiting_process.push(interval);
        }
        int count=0;
        while (!waiting_process.empty())
        {
            int end=waiting_process.front()[1];
            waiting_process.pop();
            while (!waiting_process.empty()&&waiting_process.front()[0]<end)
            {
                waiting_process.pop();
                count++;
            }
            
        }
        return count;
    }
};
// @lc code=end

