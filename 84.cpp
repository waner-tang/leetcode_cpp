#include"header_files.h"
/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> index_left;
        stack<int> s;
        s.push(0);
        index_left.push_back(-1);
        for (int i = 1; i < heights.size(); i++)
        {
            while (!s.empty())
            {
                if (heights[s.top()]>=heights[i])
                {
                    s.pop();
                }
                else
                {
                    index_left.push_back(s.top());
                    s.push(i);
                    break;
                }
                
            }
            if (s.empty())
            {
                s.push(i);
                index_left.push_back(-1);
            }
            
        }

        stack<int> s2;
        int r=heights.size()-1;
        s2.push(r);
        int a=(r+1-index_left[r]-1)*heights[r];
        for (int i = r-1; i >= 0; i--)
        {
            while (!s2.empty())
            {
                if (heights[s2.top()]>=heights[i])
                {
                    s2.pop();
                }
                else
                {
                    a=max(a,(s2.top()-index_left[i]-1)*heights[i]);
                    s2.push(i);
                    break;
                }
                
            }
            if (s2.empty())
            {
                s2.push(i);
                a=max(a,(r+1-index_left[i]-1)*heights[i]);
            }
            
        }
        return a;
    }
};
// @lc code=end

