#include"header_files.h"
/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
class Solution {
public:
    // 此题目变成回溯类型，因为需要遍历所有子树以获得答案
    // 动态规划有一个明显特征即寻求最优解
    vector<string> answer;
    vector<string> track;
    void backtrack(string& s,vector<string>& dict,int start)
    {
        if (s.length()==start)
        {
            string ans;
            for (int i = 0; i < track.size(); i++)
            {
                ans+=track[i];
                if (i!=track.size()-1)
                {
                    ans+=' ';
                }
                
            }
            answer.push_back(ans);
            return;
        }
        
        for (auto& word:dict)
        {
            if (word==s.substr(start,word.length()))
            {
                track.push_back(word);
                backtrack(s,dict,start+word.length());
                track.pop_back();
            }
            
        }
        
        
        

    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        backtrack(s,wordDict,0);
        return answer;
    }
};
// @lc code=end

