#include "header_files.h"
/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution
{
private:
    unordered_multimap<int, int> order;
    vector<int> done;

public:
    // 入度+1 出度+1
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        done.assign(numCourses, 0);
        for (auto &p : prerequisites)
        {
            order.insert({p[1], p[0]}); // start->end  出度 入度
            done[p[0]]++;
        }

        int count = 0;
        queue<int> zeroindex;
        for (int i = 0; i < numCourses; i++)
        {
            if (done[i] == 0)
            {
                count++;
                zeroindex.push(i);
            }
        }

        while (count < numCourses)
        {
            zeroindex=bfs(zeroindex);
            if (zeroindex.size()==0)
            {
                return false;
            }
            count+=zeroindex.size();
        }
        return true;
    }

    queue<int> bfs(queue<int> toprocess)
    {
        queue<int> n;
        while (!toprocess.empty())
        {
            auto range = order.equal_range(toprocess.front());
            for (auto it = range.first; it != range.second; it++)
            {
                done[it->second]--;
                if (done[it->second]==0)
                {
                    n.push(it->second);
                }
                
            }
            toprocess.pop();
        }
        return n;
    }
};
// @lc code=end
