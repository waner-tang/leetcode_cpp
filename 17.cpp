#include"header_files.h"
/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
private:
    unordered_map<char,string> dic;
    vector<string> results;
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size()==0)
        {
            return results;
        }
        
        dic.insert({'2',"abc"});
        dic.insert({'3',"def"});
        dic.insert({'4',"ghi"});
        dic.insert({'5',"jkl"});
        dic.insert({'6',"mno"});
        dic.insert({'7',"pqrs"});
        dic.insert({'8',"tuv"});
        dic.insert({'9',"wxyz"});

        string curr;
        traceback(digits,curr,0);
        return results;
    }
    void traceback(string& digits,string& curr,int start)
    {
        if (start==digits.size())
        {
            results.push_back(curr);
            return;
        }
        string choice=dic[digits[start]];
        for (auto ch:choice)
        {
            curr.push_back(ch);
            traceback(digits,curr,start+1);
            curr.pop_back();
        }
        return;
    }
};
// @lc code=end

