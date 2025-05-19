#include "header_files.h"
/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution
{
private:
    vector<vector<bool>> visited;

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        visited.assign(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                visited[i][j] = true;
                if (traceback(board, i, j, word, 0))
                {
                    return true;
                }
                visited[i][j] = false;
            }
        }
        return false;
    }
    bool traceback(vector<vector<char>> &board, int p_m, int p_n, string word, int start)
    {
        if (board[p_m][p_n] != word[start])
        {
            return false;
        }

        if (start == word.size() - 1)
        {
            return true;
        }

        if (p_m + 1 < board.size() && visited[p_m + 1][p_n] == false)
        {
            visited[p_m + 1][p_n] = true;
            if (traceback(board, p_m + 1, p_n, word, start + 1))
            {
                return true;
            }
            visited[p_m + 1][p_n] = false;
        }

        if (p_m - 1 >= 0 && visited[p_m - 1][p_n] == false)
        {
            visited[p_m - 1][p_n] = true;
            if (traceback(board, p_m - 1, p_n, word, start + 1))
            {
                return true;
            }
            visited[p_m - 1][p_n] = false;
        }

        if (p_n + 1 < board[0].size() && visited[p_m][p_n + 1] == false)
        {
            visited[p_m][p_n + 1] = true;
            if (traceback(board, p_m, p_n + 1, word, start + 1))
            {
                return true;
            }
            visited[p_m][p_n + 1] = false;
        }

        if (p_n - 1 >= 0 && visited[p_m][p_n - 1] == false)
        {
            visited[p_m][p_n - 1] = true;
            if (traceback(board, p_m, p_n - 1, word, start + 1))
            {
                return true;
            }
            visited[p_m][p_n - 1] = false;
        }

        return false;
    }
};
// @lc code=end
