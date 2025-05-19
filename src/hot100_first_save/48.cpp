#include"header_files.h"
/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for (int i = 0; 2*i < n-1; i++)
        {
            pair<int,int> start1={n-1-i,i};
            pair<int,int> start2={n-1-i,n-1-i};
            while (start1.first>i)
            {
                swap(matrix[start1.first][start1.second],matrix[start2.first][start2.second]);
                start1.first--;
                start2.second--;
            }
            start1={n-1-i,n-1-i};
            start2={i,n-1-i};
            while (start1.second>i)
            {
                swap(matrix[start1.first][start1.second],matrix[start2.first][start2.second]);
                start1.second--;
                start2.first++;
            }
            start1={i,n-1-i};
            start2={i,i};
            while (start1.first<n-1-i)
            {
                swap(matrix[start1.first][start1.second],matrix[start2.first][start2.second]);
                start1.first++;
                start2.second++;
            }
            
        }
        
    }
};
// @lc code=end

