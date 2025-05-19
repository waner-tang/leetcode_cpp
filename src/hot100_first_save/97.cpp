#include "header_files.h"
/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
class Solution
{
public:
    // 状态转移方程为dp[i,j,k]=dp[i+1,j,k+1]  (s1[i]==s3[k])+dp[i,j+1,k+1]  (s1[j]==s3[k])
    vector<vector<int>> memo;
    bool dp(string &s1, int i, string &s2, int j, string &s3, int k)
    {
        if (k == s3.length())
        {
            return true;
        }
        if (i==s1.length())
        {
            return s2.substr(j)==s3.substr(k);
        }
        if (j==s2.length())
        {
            return s1.substr(i)==s3.substr(k);
        }
        if (memo[i][j]!=-1)
        {
            return memo[i][j];
        }
        

        bool flag = false;
        if (s1[i] == s3[k])
        {
            flag = dp(s1, i + 1, s2, j, s3, k + 1);
            if (s2[j] == s3[k] && flag == false)
            {
                flag = dp(s1, i, s2, j+1, s3, k + 1);
            }
        }
        else if (s2[j] == s3[k])
        {
            flag = dp(s1, i , s2, j+1, s3, k + 1);
        }

        memo[i][j]=flag;
        return flag;
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.length()+s2.length()!=s3.length())
        {
            return false;
        }
        memo.assign(s1.length(),vector<int>(s2.length(),-1));
        return dp(s1, 0, s2, 0, s3, 0);
    }
};
// @lc code=end
