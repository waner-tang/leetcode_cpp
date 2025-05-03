#include"header_files.h"
/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 */

// @lc code=start
class Solution {
public:
    // 状态转移方程：dp[k][n]=
    // for(auto i:n res=min(res,max(dp[k][n-i],dp[k-1][i-1])+1))

    vector<vector<int>> memo;
    int superEggDrop(int k, int n) {
        memo.assign(k+1,vector<int>(n+1,-1));
        return dp(k,n);
    }

    int dp(int k,int n)
    {
        if (k==1)
        {
            return n;
        }
        if (n==0)
        {
            return 0;
        }
        
        if (memo[k][n]!=-1)
        {
            return memo[k][n];
        }
        int res=INT_MAX;
        int min_num=1,max_num=n,mid;
        while (min_num<=max_num)
        {
            mid=(min_num+max_num)/2;
            int broken=dp(k-1,mid-1)+1;
            int not_broken=dp(k,n-mid)+1;
            if(broken>not_broken)
            {
                max_num=mid-1;
                res=min(res,broken);
            }
            else
            {
                min_num=mid+1;
                res=min(res,not_broken);
            }
            
        }
        
        memo[k][n]=res;
        return res;
    }
};
// @lc code=end

