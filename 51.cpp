#include "header_files.h"
/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution
{
private:
    vector<bool> cols;
    vector<vector<string>> ans;

public:
    vector<vector<string>> solveNQueens(int n)
    {
        cols.assign(n, false);
        vector<pair<int, int>> curr;
        traceback(n, curr, 0);
        return ans;
    }
    void traceback(int n, vector<pair<int, int>> &curr, int rows)
    {
        if (rows == n)
        {
            transfer_ans(n, curr);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (!cols[i])
            {
                bool flag = true;
                for (auto &c : curr)
                {
                    if (abs(c.first - rows) == abs(c.second - i))
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag)
                {
                    cols[i] = true;
                    curr.push_back({rows, i});
                    traceback(n, curr, rows + 1);
                    cols[i] = false;
                    curr.pop_back();
                }
            }
        }
        return;
    }

    void transfer_ans(int n, vector<pair<int, int>> &curr)
    {
        vector<string> ans0(n, string(n, '.'));
        for (auto &c : curr)
        {
            ans0[c.first][c.second] = 'Q';
        }

        ans.push_back(ans0);
    }
};
// @lc code=end
