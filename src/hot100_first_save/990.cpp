#include "header_files.h"
/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

// @lc code=start
class Solution
{
public:
    unordered_map<char, char> parent;

    char find(char alpha)
    {
        if (parent[alpha]!=alpha)
        {
            parent[alpha]=find(parent[alpha]);
        }
        return parent[alpha];
        
    }

    bool equationsPossible(vector<string> &equations)
    {
        vector<pair<char, char>> seperation;
        for (char alpha = 'a'; alpha <= 'z'; alpha++)
        {
            parent[alpha] = alpha;
        }
        for (auto &equation : equations)
        {
            if (equation[1]=='!')
            {
                seperation.push_back(make_pair(equation[0],equation[3]));
            }
            else
            {
                char rooti=find(equation[0]);
                char rootj=find(equation[3]);
                if (rooti!=rootj)
                {
                    parent[rooti]=rootj;
                }
                
            }
        }

        for (auto& sep:seperation)
        {
            char rooti=find(sep.first);
            char rootj=find(sep.second);
            if (rooti==rootj)
                {
                    return false;
                }
        }
        
        return true;
    }
};
// @lc code=end
