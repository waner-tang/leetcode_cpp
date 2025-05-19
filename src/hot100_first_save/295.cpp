#include"header_files.h"
/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
class MedianFinder {
    private:
    priority_queue<int> max_first;  // 最大堆，存小数
    priority_queue<int,vector<int>,greater<int>> min_first;   // 最小堆，存大数
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (min_first.size()>max_first.size())
        { 
            if (max_first.size()==0)
            {
                if (min_first.top()>num)
                {
                    max_first.emplace(num);
                }
                else
                {
                    int n=min_first.top();
                    max_first.emplace(n);
                    min_first.pop();
                    min_first.emplace(num);
                }
                return;
            }
            
            if (min_first.top()>num)
            {
                max_first.emplace(num);
            }
            else
            {
                int n=min_first.top();
                min_first.pop();
                min_first.emplace(num);
                max_first.emplace(n);
            }
        }
        else
        {
            if (max_first.size()==0)
            {
                min_first.emplace(num);
                return;
            }
            
            if (max_first.top()>num)
            {
                int n=max_first.top();
                max_first.pop();
                max_first.emplace(num);
                min_first.emplace(n);
            }
            else
            {
                min_first.emplace(num);
            }
            
        }
        
    }
    
    double findMedian() {
        if (min_first.size()==max_first.size())
        {
            return (max_first.top()+min_first.top())/double(2);
        }
        
        return double(min_first.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

