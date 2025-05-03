#include"header_files.h"
/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
class Solution {
public:
    // 状态转移方程：res=grid[i][j]-min(dp(i+1,j),dp(i,j+1))
    // dp(i,j)=res>=0? 1:-res

    vector<vector<int>> memo;
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memo.assign(dungeon.size(),vector<int>(dungeon[0].size(),-1));
        int m=dungeon.size()-1;
        int n=dungeon[0].size()-1;
        memo[m][n]=dungeon[m][n]>=0? 1: -dungeon[m][n]+1;
        return dp(0,0,dungeon);
    }

    int dp(int i, int j,vector<vector<int>>& dungeon) 
    {
        if (i==dungeon.size()||j==dungeon[0].size())
        {
            return INT_MAX;
        }
        
        if (memo[i][j]!=-1)
        {
            return memo[i][j];
        }
        
        int res=dungeon[i][j]-min(dp(i+1,j,dungeon),dp(i,j+1,dungeon));
        memo[i][j]=res>=0? 1: -res;
        return memo[i][j];
    }
};
// @lc code=end

