#include"header_files.h"
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        if (nums[0]>0)
        {
            return ans;
        }
        if (nums[nums.size()-1]<0)
        {
            return ans;
        }
        
        for (int i = 0; i <= nums.size()-3; i++)
        {
            if (i>0&&nums[i-1]==nums[i])
            {
                continue;
            }
            
            if (nums[i]>0)
            {
                break;
            }
            
            int target=-nums[i];
            int j=i+1,k=nums.size()-1;
            while (j<k)
            {
                if (nums[j]+nums[k]==target)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    while (j<nums.size()&&nums[j]==nums[j-1])
                    {
                        j++;
                    }
                    k--;
                    while (k>=0&&nums[k]==nums[k+1])
                    {
                        k--;
                    }
                    
                }
                else if (nums[j]+nums[k]<target)
                {
                    j++;
                    while (j<nums.size()&&nums[j]==nums[j-1])
                    {
                        j++;
                    }
                }
                else
                {
                    k--;
                    while (k>=0&&nums[k]==nums[k+1])
                    {
                        k--;
                    }
                }
                
            }
            
        }
        return ans;
    }
};
// @lc code=end

