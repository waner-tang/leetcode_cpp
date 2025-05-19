#include"header_files.h"
/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int start=0;
        int end=s.size()-1;
        while (start<end)
        {
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }
};
// @lc code=end

