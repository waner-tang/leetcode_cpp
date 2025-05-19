#include "header_files.h"
/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int condition = 1; // 1 右 2 下 3 左 4 上
        int row = matrix.size();
        int col = matrix[0].size();
        int p_i = 0, p_j = 0;
        ans.push_back(matrix[p_i][p_j]);
        matrix[0][0]=101;
        while (ans.size() < row * col)
        {
            if (condition==1)
            {
                if (p_j + 1 < col && matrix[p_i][p_j+1] != 101)
                {
                    p_j++;
                }
                else
                {
                    p_i++;
                    condition=2;
                }
            }
            else if (condition==2)
            {
                if (p_i + 1 < row && matrix[p_i+1][p_j] != 101)
                {
                    p_i++;
                }
                else
                {
                    p_j--;
                    condition=3;
                }
            }
            else if (condition==3)
            {
                if (p_j - 1 >= 0 && matrix[p_i][p_j-1] != 101)
                {
                    p_j--;
                }
                else
                {
                    p_i--;
                    condition=4;
                }
            }
            else
            {
                if (p_i - 1 >= 0 && matrix[p_i-1][p_j] != 101)
                {
                    p_i--;
                }
                else
                {
                    p_j++;
                    condition=1;
                }
            }
            ans.push_back(matrix[p_i][p_j]);
            matrix[p_i][p_j] = 101;            
                }
        return ans;
    }

};
// @lc code=end
