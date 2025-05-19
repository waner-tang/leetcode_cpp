#include "header_files.h"
/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> compare;
        for (auto &str : strs)
        {
            vector<int> res(26, 0);
            for (auto &ch : str)
            {
                res[ch - 'a']++;
            }
            string res0;
            for (int i = 0; i < 26; i++)
            {
                res0.push_back(i + 'a');
                res0.append(to_string(res[i]));
            }

            if (compare.find(res0) != compare.end())
            {
                compare[res0].push_back(str);
            }
            else
            {
                vector<string> vs;
                compare.insert({res0, vs});
                compare[res0].push_back(str);
            }
        }
        vector<vector<string>> ans;
        auto it = compare.begin();
        for (; it != compare.end(); it++)
        {
            ans.push_back(it->second);
        }

        return ans;
    }
};
// @lc code=end
