#include"header_files.h"
/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    // 状态转移方程：
    // dp(i,j)=dp(i-1,j-1)   (word1[i]==word[j])
    //       =min(dp(i-1,j)+1, dp(i,j-1)+1, dp(i-1,j-1)+1)   (else)
    //   删除、插入、替换

    vector<vector<int>> memo;
    int minDistance(string word1, string word2) {
        if (word1.length()==0||word2.length()==0)
        {
            return max(word1.length(),word2.length());
        }
        
        memo.assign(word1.length(),vector<int>(word2.length(),-1));
        return dp(word1,word1.length()-1,word2,word2.length()-1);
    }

    int dp(string& word1, int i, string& word2, int j)
    {
        if (i==-1)
        {
            return j+1;
        }
        if (j==-1)
        {
            return i+1;
        }
        
        if (memo[i][j]!=-1)
        {
            return memo[i][j];
        }
        

        if (word1[i]==word2[j])
        {
            memo[i][j]=dp(word1,i-1,word2,j-1);
        }
        else
        {
            memo[i][j]=min(dp(word1,i,word2,j-1)+1,dp(word1,i-1,word2,j)+1);
            memo[i][j]=min(memo[i][j],dp(word1,i-1,word2,j-1)+1);
        }
        
        return memo[i][j];
    }
};
// @lc code=end

