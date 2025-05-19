#include"header_files.h"
/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    vector<int> memo;
    int recursion(int m)
    {
        if (m==1)
        {
            return 1;
        }
        else if (m==0)
        {
            return 0;
        }

        if (memo[m]!=-1)
        {
            return memo[m];
        }
        
        memo[m]=recursion(m-1)+recursion(m-2);
        return memo[m];
        
    }
    int fib(int n) {
        if (n==0)
        {
            return 0;
        }
        if (n==1)
        {
            return 1;
        }
        
        memo.assign(n+1,-1);
        memo[0]=0;
        memo[1]=1;
        return recursion(n);
    }
};
// @lc code=end

