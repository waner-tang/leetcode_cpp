#include"header_files.h"
/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
    //状态转移方程：dp(i,j)=
    // if s[i]==p[j]||p[j]=='.'  //匹配
        // if p[j+1]=='*'   //a a*a    aa a*
            // return dp(i,j+2)||dp(i+1,j)
        //  else
        //  // return dp(i+1,j+1)   //a a
    // else   //不匹配
        //  if p[j+1]=='*'     
            // return dp(i,j+2)   //a c*a
        // else
            // return false      //a c
public:
    vector<vector<int>> memo;
    bool dp(string& s, int index_s, string& p, int index_p)
    {
        // data base
        if (index_p==p.length())
        {
            return index_s==s.length();
        }
        if (index_s==s.length())
        {
            if ((p.length()-index_p)%2==1)
            {
                return false;
            }
            else
            {
                for (int i = index_p; i < p.length(); i+=2)
                {
                    if (p[i+1]!='*')
                    {
                        return false;
                    }
                }
                return true;
            }
        }


        if (memo[index_s][index_p]!=-1)
        {
            return memo[index_s][index_p];
        }
        
        bool flag;
        if (s[index_s]==p[index_p]||p[index_p]=='.')  // 匹配
        {
            // 匹配0次或者多次
            if (index_p<p.length()-1&&p[index_p+1]=='*')
            {
                flag=dp(s,index_s,p,index_p+2)||dp(s,index_s+1,p,index_p);
            }
            // 匹配1次
            else
            {
                flag=dp(s,index_s+1,p,index_p+1);
            }
        }
        else   // 不匹配
        {
            if (index_p<p.length()-1&&p[index_p+1]=='*')
            {
                flag=dp(s,index_s,p,index_p+2);
            }
            else
            {
                flag=false;
            }
        }
        
        memo[index_s][index_p]=flag;
        return flag;
    }


    bool isMatch(string s, string p) {
        memo.assign(s.length(),vector<int>(p.length(),-1));
        return dp(s,0,p,0);
    }
};
// @lc code=end

