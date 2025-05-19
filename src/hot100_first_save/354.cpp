#include"header_files.h"
/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](auto& e1,auto& e2){
            return e1[0]<e2[0]||(e1[0]==e2[0]&&e1[1]>e2[1]);
        });
        vector<int> top;
        top.push_back(envelopes[0][1]);
        for (int i = 0; i < envelopes.size(); i++)
        {
            int left=0;
            int right=top.size()-1;
            while (left<right)
            {
                int mid=(left+right)/2;
                if (envelopes[i][1]<top[mid])
                {
                    right=mid;
                }
                else if (envelopes[i][1]>top[mid])
                {
                    left=mid+1;
                }
                else
                {
                    right=mid;
                }
            }
            
            if (left==top.size()-1&&top[left]<envelopes[i][1])
            {
                top.push_back(envelopes[i][1]);
            }
            else
            {
                top[left]=envelopes[i][1];
            }
            
        }
        return top.size();
    }
};
// @lc code=end

