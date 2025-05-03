#include "header_files.h"
/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> memo;
    int dp(string &t1, int i, string &t2, int j)
    {
        if (i == t1.length() || j == t2.length())
        {
            return 0;
        }
        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }

        if (t1[i] == t2[j])
        {
            memo[i][j] = 1 + dp(t1, i + 1, t2, j + 1);
        }
        else
        {
            memo[i][j] = max(dp(t1, i + 1, t2, j), dp(t1, i, t2, j + 1));
        }

        return memo[i][j];
    }

    int minDistance(string word1, string word2)
    {
        int m=word1.length();
        int n=word2.length();
        memo.assign(m,vector<int>(n,-1));

        return m+n-2*dp(word1,0,word2,0);
    }
};
// @lc code=end
