#include"header_files.h"
/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    // 状态转移方程：dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j]
    int minPathSum(vector<vector<int>>& grid) {
        // int m=grid.size();
        // int n=grid[0].size();
        // vector<vector<int>> dp(m,vector<int>(n));
        // dp[0][0]=grid[0][0];
        // for (int i = 1; i < m; i++)
        // {
        //     dp[i][0]=dp[i-1][0]+grid[i][0];
        // }
        // for (int i = 1; i < n; i++)
        // {
        //     dp[0][i]=dp[0][i-1]+grid[0][i];
        // }
        
        // for (int i = 1; i < m; i++)
        // {
        //     for (int j = 1; j < n; j++)
        //     {
        //         dp[i][j]=min(dp[i-1][j], dp[i][j-1])+grid[i][j];
        //     }
            
        // }
        // return dp[m-1][n-1];

        // 节省运算空间
        int m=grid.size();
        int n=grid[0].size();
        for (int i = 1; i < m; i++)
        {
            grid[i][0]=grid[i-1][0]+grid[i][0];
        }
        for (int i = 1; i < n; i++)
        {
            grid[0][i]=grid[0][i-1]+grid[0][i];
        }
        
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                grid[i][j]=min(grid[i-1][j], grid[i][j-1])+grid[i][j];
            }
            
        }
        return grid[m-1][n-1];
    }
};
// @lc code=end

