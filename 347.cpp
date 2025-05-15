#include"header_files.h"
/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
private:
    unordered_map<int,int> m;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> nums_max;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i])!=m.end())
            {
                m[nums[i]]++;
            }
            else
            {
                nums_max.push_back(nums[i]);
                m[nums[i]]=1;
            }
        }
        
        buildHeapify(nums_max,k);
        for (int i = k; i < nums_max.size(); i++)
        {
            if (m[nums_max[i]]>m[nums_max[0]])
            {
                swap(nums_max[i],nums_max[0]);
                minHeapify(nums_max,0,k);
            }
            
        }
        nums_max.erase(nums_max.begin()+k,nums_max.end());
        return nums_max;
    }
    void buildHeapify(vector<int>& nums_max, int heapsize)
    {
        for (int i = heapsize/2-1; i >= 0; i--)
        {
            minHeapify(nums_max,i,heapsize);
        }
        
    }
    void minHeapify(vector<int>& nums_max,int i, int heapsize)
    {
        int l=2*i+1, r=2*i+2, mini=i;
        if (l<heapsize&&m[nums_max[l]]<m[nums_max[mini]])
        {
            mini=l;
        }
        if (r<heapsize&&m[nums_max[r]]<m[nums_max[mini]])
        {
            mini=r;
        }

        if (mini!=i)
        {
            swap(nums_max[mini],nums_max[i]);
            minHeapify(nums_max,mini,heapsize);
        }
        
    }
};
// @lc code=end

