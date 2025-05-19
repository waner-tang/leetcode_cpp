#include "header_files.h"
/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution
{
private:
    vector<vector<int>> results;

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> curr;
        backtrack(candidates, curr, target, 0);
        return results;
    }
    void backtrack(vector<int> &candidates, vector<int> &curr, int target, int start)
    {
        if (start == candidates.size() || target < 0)
        {
            return;
        }
        if (target == 0)
        {
            results.push_back(curr);
            return;
        }
        curr.push_back(candidates[start]);
        backtrack(candidates, curr, target - candidates[start], start);
        curr.pop_back();

        backtrack(candidates, curr, target, start+1);

        return;
    }
};
// @lc code=end
