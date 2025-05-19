#include"header_files.h"
/*
 * @lc app=leetcode.cn id=1312 lang=cpp
 *
 * [1312] 让字符串成为回文串的最少插入次数
 */

// @lc code=start
class Solution {
public:
    int minInsertions(string s) {
        if (s.length()==1)
        {
            return 0;
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
        
        return s.length()-dp[0][s.length()-1];
    }
};
// @lc code=end

