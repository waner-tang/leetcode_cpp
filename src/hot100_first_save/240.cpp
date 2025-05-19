#include"header_files.h"
/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        pair<int,int> start={0,col-1};
        while (start.second>=0&&start.first<row)
        {
            if (matrix[start.first][start.second]==target)
            {
                return true;
            }
            else if (matrix[start.first][start.second]>target)
            {
                start.second--;
            }
            else
            {
                start.first++;
            }
            
        }
        return false;
    }
};
// @lc code=end

