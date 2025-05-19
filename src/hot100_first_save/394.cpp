#include "header_files.h"
/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution
{
public:
    string decodeString(string s)
    {
        stack<char> res;
        for (auto &ch : s)
        {
            if (ch != ']')
            {
                res.push(ch);
            }
            else
            {
                string s0;
                while (res.top() != '[')
                {
                    s0.push_back(res.top());
                    res.pop();
                }
                res.pop();
                string num;
                while (!res.empty() && res.top() - '0' >= 0 && res.top() - '0' <= 9)
                {
                    num.push_back(res.top());
                    res.pop();
                }
                int n = 0;
                for (int i = 0; i < num.length(); i++)
                {
                    n += (num[i]-'0') * pow(10,i);
                }
                string str_curr;
                while (n > 0)
                {
                    str_curr.append(s0);
                    n--;
                }
                for (int i = str_curr.length() - 1; i >= 0; i--)
                {
                    res.push(str_curr[i]);
                }
            }
        }
        string ans;
        while (!res.empty())
        {
            ans.push_back(res.top());
            res.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

};
// @lc code=end
