#include"header_files.h"
/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size()>s.length())
        {
            return "";
        }
        vector<int> fre_t('z'-'A'+1,0);
        for (auto ch:t)
        {
            fre_t[ch-'A']++;
        }
        vector<int> fre_s('z'-'A'+1,0);
        int valid=0;
        int curr_l=0;
        int l=0,r=s.size()+1;
        for (int i = 0; i < s.size(); i++)
        {
            fre_s[s[i]-'A']++;
            if (fre_s[s[i]-'A']<=fre_t[s[i]-'A'])
            {
                valid++;
            }
            if (valid==t.size())
            {
                while (fre_s[s[curr_l]-'A']>fre_t[s[curr_l]-'A'])
                {
                    fre_s[s[curr_l]-'A']--;
                    curr_l++;
                }
                if (i-curr_l<r-l)
                {
                    r=i;
                    l=curr_l;
                }
                
            }
            
        }
        if (r==s.size()+1)
        {
            return "";
        }
        
        return s.substr(l,r-l+1);
    }
};
// @lc code=end

