#include"header_files.h"
/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;
        if (p.size()>s.size())
        {
            return ans;
        }
        vector<int> fre_s(26,0),fre_p(26,0);
        for (auto ch:p)
        {
            fre_p[ch-'a']++;
        }
        
        for (int i = 0; i < s.size(); i++)
        {
            fre_s[s[i]-'a']++;
            if (i>=p.size())
            {
                fre_s[s[i-p.size()]-'a']--;
            }
            if (fre_s==fre_p)
            {
                ans.push_back(i-p.size()+1);
            }
            
        }
        return ans;
    }
};
// @lc code=end

