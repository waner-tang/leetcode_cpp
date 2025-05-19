#include"header_files.h"
/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution {
public:
    // 状态转移方程：
    // dp[i][j]=dp[i+1][j-1]+2 (s[i]=s[j])
    //         =max(dp[i+1][j], dp[i][j-1]) (else)
    int longestPalindromeSubseq(string s) {
        if (s.length()==1)
        {
            return 1;
        }
        
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
        for (int i = 0; i < s.length(); i++)
        {
            dp[i][i]=1;
        }
        
        // 倒着遍历dp数组
        for (int i = s.length()-1; i >= 0; i--)
        {
            for (int j = i+1; j < s.length(); j++)
            {
                if (s[i]==s[j])
                {
                    dp[i][j]=dp[i+1][j-1]+2;
                }
                else
                {
                    dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
                }
                
                
            }
            
        }
        
        return dp[0][s.length()-1];
    }
};
// @lc code=end

