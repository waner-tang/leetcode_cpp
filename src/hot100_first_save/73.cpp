#include"header_files.h"
/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowNum=matrix.size();
        int colNum=matrix[0].size();
        vector<bool> rows(rowNum,false);
        vector<bool> cols(colNum,false);
        for (size_t i = 0; i < rowNum; i++)
        {
            for (size_t j = 0; j < colNum; j++)
            {
                if (rows[i]==false&&matrix[i][j]==0)
                {
                    rows[i]=true;
                }
                if (cols[j]==false&&matrix[i][j]==0)
                {
                    cols[j]=true;
                }
            }
            
        }
        for (size_t i = 0; i < rowNum; i++)
        {
            for (size_t j = 0; j < colNum; j++)
            {
                if (rows[i]||cols[j])
                {
                    matrix[i][j]=0;
                }
                
            }
            
        }
    }
};
// @lc code=end

