#include "header_files.h"
/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution
{
public:
    //自底向上动态规划

        // dp[状态][字符] = 下个状态
        vector<vector<int>> dp;
        void KMP(string& pat)
        {
            dp.assign(pat.length(),vector<int>(256,0));
            dp[0][pat[0]]=1;
            int x=0;   // 影子状态，即除了对应的那个字母会让当前状态+1外，其余状态与影子状态一致
            for (int i = 1; i < pat.length(); i++)
            {
                for (int j = 0; j < 256; j++)
                {
                    dp[i][j]=dp[x][j];
                }
                dp[i][pat[i]]=i+1;
                x=dp[x][pat[i]];
            }

        }
        int strStr(string haystack, string needle) {
            KMP(needle);
            if (haystack.length()<needle.length())
            {
                return -1;
            }
            int flag=0;
            for (int i=0;i<haystack.length();i++)
            {
                flag=dp[flag][haystack[i]];
                if (flag==needle.length())
                {
                    return i-flag+1;;
                }

            }
            return -1;
        }

};
// @lc code=end
