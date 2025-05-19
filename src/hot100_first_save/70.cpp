#include"header_files.h"
/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    // 状态转移方程：dp[i]=dp[i-1]+dp[i-2]
    
    int climbStairs(int n) {
        if (n==1)
        {
            return 1;
        }
        if (n==2)
        {
            return 2;
        }
        
        int before=2;
        int before2=1;
        int current;
        for (int i = 3; i <= n; i++)
        {
            current=before+before2;
            before2=before;
            before=current;
        }
        return current;
    }
};
// @lc code=end

