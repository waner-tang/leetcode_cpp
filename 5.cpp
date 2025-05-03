#include"header_files.h"
/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    // 状态转移方程：dp[i][j]=dp[i+1][j-1]&&s[i]==s[j]  
    string longestPalindrome(string s) {
        if (s.length()==1)
        {
            return s;
        }
        
        vector<vector<bool>> dp(s.length(),vector<bool>(s.length()));
        string max_string;
        max_string=s[0];
        for (int i = 0; i < s.length(); i++)
        {
            dp[i][i]=true;
            if (i!=s.length()-1)
            {
                dp[i][i+1]=s[i]==s[i+1];
                if (dp[i][i+1])
                {
                    max_string=s.substr(i,2);
                }  
            }
            
        }
        
        for (int i = 2; i < s.length(); i++)
        {
            for (int j = 0; j < s.length()-i; j++)
            {
                dp[j][j+i]=dp[j+1][j+i-1]&&s[j]==s[j+i];
                if (dp[j][j+i])
                {
                    max_string=s.substr(j,i+1);
                }
                
            }
            
        }
        return max_string;
    }
};
// @lc code=end

