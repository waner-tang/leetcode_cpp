#include "header_files.h"
/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution
{
public:
    // 状态转移方程为dp[i,j]=1+dp[i+1,j+1]  (text1[i]==text2[j])
    // dp[i,j]=max(dp[i+1,j],dp[i,j+1])  (text1[i]!=text2[j])

    vector<vector<int>> memo;
    int dp(string& t1, int i, string& t2, int j)
    {
        if (i==t1.length()||j==t2.length())
        {
            return 0;
        }
        if (memo[i][j]!=-1)
        {
            return memo[i][j];
        }

        if (t1[i]==t2[j])
        {
            memo[i][j]=1+dp(t1,i+1,t2,j+1);
        }
        else
        {
            memo[i][j]=max(dp(t1,i+1,t2,j),dp(t1,i,t2,j+1));
        }
        
        return memo[i][j];
        
        
        
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int m=text1.length();
        int n=text2.length();
        memo.assign(m,vector<int>(n,-1));

        return dp(text1,0,text2,0);
    }
};
// @lc code=end
