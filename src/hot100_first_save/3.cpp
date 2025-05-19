#include"header_files.h"
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 转变思路，哈希表用于记录最后出现的索引，由此不需要重复遍历与重新构建哈希表
        if (s.size()==0)
        {
            return 0;
        }

        unordered_map<char,int> last_index;
        int start=0;
        int num=0;
        for (int i = 0; i < s.size(); i++)
        {
            if (last_index.insert({s[i],i}).second||last_index[s[i]]<start)
            {
                last_index[s[i]]=i;
            }
            else
            {
                num=max(i-start,num);
                start=last_index[s[i]]+1;
                last_index[s[i]]=i;
                
            }
            
        }
        return max(num,int(s.size()-start));
    }
};
// @lc code=end

