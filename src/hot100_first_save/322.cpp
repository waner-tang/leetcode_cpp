#include"header_files.h"
/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    // 状态转移方程：
    //{dp[i]=min(1+dp[i-coin])  //i-coin>=0&&dp[i-coin]!=-1}
    //dp[i]=-1   // 无法进入上述循环
    int coinChange(vector<int>& coins, int amount) {
        if (amount==0)
        {
            return 0;
        }
        
        sort(coins.begin(),coins.end(),greater<int>());
        vector<int> dp(amount+1,-1);
        dp[0]=0;
        int start=-1;
        for (int i = 0; i < coins.size(); i++)
        {
            if (coins[i]<=amount)
            {
                if (start==-1)
                {
                    start=i;
                }
                dp[coins[i]]=1;
            }
            
        }
        if (start==-1)
        {
            return -1;
        }
        
        for (int i = 1; i < dp.size(); i++)
        {
            int min_num=INT_MAX;
            bool flag=0;
            for (int j=start;j<coins.size();j++)
            {
                int coin=coins[j];
                if (i-coin>=0&&dp[i-coin]!=-1)
                {
                    flag=1;
                    min_num=min(min_num,1+dp[i-coin]);
                }
            } 
            if (flag)
            {
                dp[i]=min_num;
            }
            
        }
        return dp[amount];
    }
};
// @lc code=end

