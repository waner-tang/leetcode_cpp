#include"header_files.h"
/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
private:
    vector<vector<string>> ans;
public:
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        traceback(s,0,0,curr);
        return ans;
    }
    void traceback(string& s, int start,int end,vector<string>& curr)
    {
        if (start==s.length())
        {
            ans.push_back(curr);
            return;
        }
        if (end==s.length())
        {
            return;
        }
        
        if (check(s,start,end))
        {
            curr.push_back(s.substr(start,end-start+1));
            traceback(s,end+1,end+1,curr);
            curr.pop_back();
        }
        
        traceback(s,start,end+1,curr);
        return;
    }

    bool check(string& s, int start,int end)
    {
        while (start<end)
        {
            if (s[start]==s[end])
            {
                start++;
                end--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

