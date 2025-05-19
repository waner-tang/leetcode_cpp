#include "header_files.h"
/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution
{
public:
    // 状态转移方程：
    // dp[i]=存在len,s.t dp[i]=(s[i,i+len)==wordDict)&&dp[i+len]

    vector<int> memo;
    unordered_set<string> dict;
    bool wordBreak(string s, vector<string> &wordDict)
    {
        memo.assign(s.length()+1,-1);
        dict.insert(wordDict.begin(),wordDict.end());
        return dp(s,0);
    }

    int dp(string& s, int start)
    {
        if (start==s.length())
        {
            return true;
        }
        
        if (memo[start]!=-1)
        {
            return memo[start];
        }
        
        bool subProblem=false;
        for (int i = 1; i+start <=s.length() ; i++)
        {
            if (dict.find(s.substr(start,i))!=dict.end())
            {
                subProblem=dp(s,i+start);
            }
            if (subProblem==true)
            {
                memo[start]=1;
                break;
            }
        }
        
        if (subProblem)
        {
            return true;
        }
        else
        {
            memo[start]=0;
            return false;
        }
        
        
    }
};
// @lc code=end
