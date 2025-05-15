#include"header_files.h"
/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int,vector<int>,greater<int>> q;  // 最小堆 实际使用
        // for(int i=0;i<nums.size();i++)
        // {
        //     if (q.size()<k)
        //     {
        //         q.emplace(nums[i]);
        //         continue;
        //     }
        //     if (q.top()<nums[i])
        //     {
        //         q.pop();
        //         q.emplace(nums[i]);
        //     }
            
        // }
        // return q.top();

        buildHeapify(nums,k);
        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i]>nums[0])
            {
                swap(nums[i],nums[0]);
                minHeapify(nums,0,k);
            }
            
        }
        return nums[0];
    }

    void buildHeapify(vector<int>& nums,int heapsize)
    {
        for (int i = heapsize/2-1; i >=0; i--)
        {
            minHeapify(nums,i,heapsize);
        }
        
    }
    void minHeapify(vector<int>& nums, int i, int heapsize)
    {
        int l=2*i+1,r=2*i+2 ,mini=i;
        if (l<heapsize&&nums[l]<nums[mini])
        {
            mini=l;
        }
        if (r<heapsize&&nums[r]<nums[mini])
        {
            mini=r;
        }
        if (mini!=i)
        {
            swap(nums[i],nums[mini]);
            minHeapify(nums,mini,heapsize);
        }
        
    }
};
// @lc code=end

