#include"header_files.h"
/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    // 状态转移方程：
    // dp[i]=0  (s[i]=='(')
    // dp[i]=2+dp[i-2]   (s[i]==')'&&s[i-1]=='(')
    // dp[i]= s[i-dp[i-1]-1]=='('&&dp[i-1]!=0 ? dp[i-1]+2+((i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0)) : 0  (s[i]==')'&&s[i-1]==')')
    int longestValidParentheses(string s) {
        if (s.length()==0||s.length()==1)
        {
            return 0;
        }
        
        vector<int> dp(s.length());
        dp[0]=0;
        dp[1]= s[1]==')'&&s[0]=='(' ? 2 :0;
        int max_count=max(dp[0],dp[1]);
        for (int i = 2; i < s.length(); i++)
        {
            if (s[i]=='(')
            {
                dp[i]=0;
            }
            else if (s[i]==')'&&s[i-1]=='(')
            {
                dp[i]=2+dp[i-2];
            }
            else
            {
                dp[i]= i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='('&&dp[i-1]!=0 ? 2+dp[i-1] : 0;
                if (dp[i]!=0&&i-dp[i-1]-1-1>=0)
                {
                    dp[i]+=dp[i-dp[i-1]-1-1];
                }
                
            }
            
            max_count=max(max_count,dp[i]);
        }
        
        return max_count;
    }
};
// @lc code=end

