#include"header_files.h"
/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
private:
    vector<int> ans;
public:
    vector<int> partitionLabels(string s) {
        // greedy(s,0);
        // return ans;

        vector<int> pos(26,-1);
        for (int i = 0; i < s.length(); i++)
        {
            pos[s[i]-'a']=i;
        }
        
        int start=0,end=0;
        for (int i = 0; i < s.length(); i++)
        {
            end=max(pos[s[i]-'a'],end);
            if (end==i)
            {
                ans.push_back(end-start+1);
                end++;
                start=end;
            }
            
        }
        return ans;
    }

    // void greedy(string& s,int start)
    // {
    //     if (start>=s.length())
    //     {
    //         return;
    //     }
        
    //     int end=start;
    //     int max_index=toCheck( s, start, end);
    //     while (max_index!=-1)
    //     {
    //         end=max_index;
    //         max_index=toCheck(s,start,end);
    //     }
    //     ans.push_back(end-start+1);
    //     greedy(s,end+1);
    //     return;
    // }
    
    // int toCheck(string& s,int start,int end){
    //     if(end==s.length()-1)
    //     {
    //         return -1;
    //     }

    //     int max_index=-1;
    //     unordered_set<char> se;
    //     for (int i = start; i <= end; i++)
    //     {
    //         se.insert(s[i]);
    //     }
        
    //     for (int i = end+1; i < s.length(); i++)
    //     {
    //         if (se.find(s[i])!=se.end())
    //         {
    //             max_index=i;
    //         }
            
    //     }
        
    //     return max_index;
    // }
};
// @lc code=end

