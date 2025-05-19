#include"header_files.h"
/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    // 状态转移方程：dp(n)=min(1+dp(n-k^2))(1<=k^2<=n)
    vector<int> memo;
    int numSquares(int n) {
        memo.assign(n+1,-1);
        return dp(n);
    }
    int dp(int n)
    {
        if (n==0)
        {
            return 0;
        }
        if (memo[n]!=-1)
        {
            return memo[n];
        }
        
        int min_count=n;
        for (int i = 1; i*i <= n; i++)
        {
            int count=1+dp(n-i*i);
            min_count=min(min_count,count);
        }
        memo[n]=min_count;
        return memo[n];
    }
};
// @lc code=end

