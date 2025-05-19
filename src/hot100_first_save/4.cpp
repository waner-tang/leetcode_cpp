#include"header_files.h"
/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total=nums1.size()+nums2.size();
        if(total%2==0)
        {
            int val1=findKth(nums1,0,nums2,0,total/2);
            int val2=findKth(nums1,0,nums2,0,total/2+1);
            return (val1+val2)/double(2);
        }
        else
        {
            return findKth(nums1,0,nums2,0,total/2+1);
        }
        
    }
    int findKth(vector<int>& nums1,int s1, vector<int>& nums2,int s2,int k)
    {
        if (s1>=nums1.size())
        {
            return nums2[s2+k-1];
        }
        if (s2>=nums2.size())
        {
            return nums1[s1+k-1];
        }
        if (k==1)
        {
            return min(nums1[s1],nums2[s2]);
        }
        
        
        int val1=s1+k/2-1<nums1.size() ? nums1[s1+k/2-1] :INT_MAX;
        int val2=s2+k/2-1<nums2.size() ? nums2[s2+k/2-1] :INT_MAX;
        if (val1>val2)
        {
            return findKth(nums1,s1,nums2,s2+k/2,k-k/2);
        }
        else
        {
            return findKth(nums1,s1+k/2,nums2,s2,k-k/2);
        }
        
        
    }
};
// @lc code=end

