#include"header_files.h"
/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](vector<int>& a,vector<int>& b){
            return a[1]<b[1];
        });
        queue<vector<int>> waiting_process;
        for (auto& p : points) {
            waiting_process.push(p);
        }
        int count=0;
        while (!waiting_process.empty())
        {
            count++;
            int end=waiting_process.front()[1];
            waiting_process.pop();
            while (!waiting_process.empty()&&waiting_process.front()[0]<=end)
            {
                waiting_process.pop();
            }
            
        }
        return count;
    }
};
// @lc code=end

