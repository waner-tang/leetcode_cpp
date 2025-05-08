#include"header_files.h"
/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> results;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> visited;
        vector<int> curr;
        traceback(nums,curr,visited);
        return results;
    }
    void traceback(vector<int>& nums, vector<int>& curr,unordered_set<int>& visited){
        if (visited.size()==nums.size())
        {
            results.push_back(curr);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (visited.find(nums[i])==visited.end())
            {
                curr.push_back(nums[i]);
                visited.insert(nums[i]);
                traceback(nums,curr,visited);
                visited.erase(nums[i]);
                curr.pop_back();
            }
            
        }
        return;
    }
};
// @lc code=end

