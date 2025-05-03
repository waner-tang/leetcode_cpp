#include"header_files.h"
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    struct Sum{
        int lSum,rSum,mSum,iSum;
    };
    
    Sum comparison(Sum& lsum,Sum& rsum)
    {
        int lSum=max(lsum.lSum, lsum.iSum+rsum.lSum);
        int rSum=max(rsum.rSum, rsum.iSum+lsum.rSum);
        int iSum=lsum.iSum+rsum.iSum;
        int mSum=max(max(lsum.mSum,rsum.mSum),lsum.rSum+rsum.lSum);
        return Sum{lSum,rSum,mSum,iSum};
    }

    Sum recursion(vector<int>& nums,int l,int r)
    {
        if(l==r) //终止条件
        {
            // Sum s{nums[l],nums[l],nums[l],nums[l]};
            // return s;
            //下述等价
            return Sum{nums[l],nums[l],nums[l],nums[l]};
        }

        //拆解
        int m=(l+r)/2;
        Sum lsum=recursion(nums,l,m);
        Sum rsum=recursion(nums,m+1,r);
        return comparison(lsum,rsum);  //返回的值
    }

    int maxSubArray(vector<int>& nums) {
        return recursion(nums,0,nums.size()-1).mSum;
    }
};
// @lc code=end

