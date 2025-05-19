#include"header_files.h"
/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes=0;
        while (bfs(grid))
        {
            minutes++;
        }
        for (int i = 0; i <= grid.size()-1; i++)
        {
            for (int j = 0; j <= grid[0].size()-1; j++)
            {
                if (grid[i][j]==1)
                {
                    return -1;
                }
                
            }
            
        }
        
        return minutes;
    }
    bool bfs(vector<vector<int>>& grid)
    {
        int m=grid.size()-1;
        int n=grid[0].size()-1;
        bool change=false;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (grid[i][j]==2)
                {
                    if (i+1<=m&&grid[i+1][j]==1)
                    {
                        change=true;
                        grid[i+1][j]=3;
                    }
                    if (i-1>=0&&grid[i-1][j]==1)
                    {
                        change=true;
                        grid[i-1][j]=3;
                    }
                    if (j+1<=n&&grid[i][j+1]==1)
                    {
                        change=true;
                        grid[i][j+1]=3;
                    }
                    if (j-1>=0&&grid[i][j-1]==1)
                    {
                        change=true;
                        grid[i][j-1]=3;
                    }
                }
                
            }
            
        }
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (grid[i][j]==3)
                {
                    grid[i][j]=2;
                }
                
            }
        }
        
        return change;
    }
};
// @lc code=end

