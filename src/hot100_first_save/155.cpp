#include"header_files.h"
/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
private:
    stack<int> s;
    stack<int> s_min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        // stack<int> res;
        // while (!s_min.empty()&&s_min.top()<val)
        // {
        //     res.push(s_min.top());
        //     s_min.pop();
        // }
        // s_min.push(val);
        // while (!res.empty())
        // {
        //     s_min.push(res.top());
        //     res.pop();
        // }
        if (s_min.empty())
        {
            s_min.push(val);
            return;
        }
        
        s_min.push(min(s_min.top(),val));
    }
    
    void pop() {
        int n=s.top();
        s.pop();
        
        // stack<int> res;
        // while (s_min.top()!=n)
        // {
        //     res.push(s_min.top());
        //     s_min.pop();
        // }
        // s_min.pop();
        // while (!res.empty())
        // {
        //     s_min.push(res.top());
        //     res.pop();
        // }

        s_min.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return s_min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

