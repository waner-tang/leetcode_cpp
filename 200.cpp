#include "header_files.h"
/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution
{
public:
    // DFS
    //  int num;
    //  // 岛屿构造 岛屿大小x2 当前位置x2
    //  void traverse(vector<vector<char>> &grid, int m, int n, int position_m, int position_n)
    //  {
    //      if (position_m < 0 || position_m > m || position_n < 0 || position_n > n)
    //      {
    //          return;
    //      }
    //      if (grid[position_m][position_n]=='0')
    //      {
    //          return;
    //      }

    //     grid[position_m][position_n]='0';
    //     traverse(grid, m, n, position_m+1, position_n);
    //     traverse(grid,  m , n, position_m, position_n+1);
    //     traverse(grid, m , n , position_m-1, position_n);
    //     traverse(grid,  m , n , position_m, position_n-1);
    // }
    // int numIslands(vector<vector<char>> &grid)
    // {
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     num = 0;
    //     for (int i = 0; i < m; i++)
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             if (grid[i][j]=='1')
    //             {
    //                 num++;
    //                 traverse(grid, m - 1, n - 1, i, j);
    //             }
    //         }
    //     }

    //     return num;
    // }

    // BFS
    // 岛屿构造 岛屿大小x2 当前位置x2
    void traverse(vector<vector<char>> &grid, int m, int n, int position_m, int position_n)
    {
        queue<vector<int>> order;
        vector<vector<int>> change = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        order.push({position_m, position_n});
        while (!order.empty())
        {
            int x = order.front()[0];
            int y = order.front()[1];
            order.pop();
            for (int i = 0; i < 4; i++)
            {
                if (x + change[i][0] >= 0 && x + change[i][0] < m && y + change[i][1] >= 0 && y + change[i][1] < n && grid[x + change[i][0]][y + change[i][1]] == '1')
                {
                    order.push({x + change[i][0], y + change[i][1]});
                    grid[x + change[i][0]][y + change[i][1]] = '0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int num = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    num++;
                    traverse(grid, m, n, i, j);
                }
            }
        }
        return num;
    }
};
// @lc code=end
