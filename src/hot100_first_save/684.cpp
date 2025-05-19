#include "header_files.h"
/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class Solution
{
public:
    vector<int> parent;

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        parent.reserve(edges.size()+1);
        for (int i = 1; i <= edges.size(); i++)
        {
            parent[i] = i;
        }
        for (auto &edge : edges)
        {
            int rooti = find(edge[0]);
            int rootj = find(edge[1]);
            if (rooti != rootj)
            {
                parent[rooti]=rootj;
            }
            else
            {
                return edge;
            }
            
        }
        return vector<int>{};
    }
};
// @lc code=end
