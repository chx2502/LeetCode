//
//  main.cpp
//  LeetCode_225_用队列实现栈
//
//  Created by chx on 2020/3/1.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        capacity = 0;
        t = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        t = x;
        if (!q2.empty()) q2.push(x);
        else q1.push(x);
        capacity++;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        capacity--;
        if (!q1.empty()) return clearQueue(q1, q2);
        else return clearQueue(q2, q1);
    }
    
    int clearQueue(queue<int>& q1, queue<int>& q2) {
        int ret = 0;
        while (!q1.empty()) {
            ret = q1.front();
            q1.pop();
            if (!q1.empty()) {
                t = ret;
                q2.push(ret);
            }
        }
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        return t;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return capacity == 0;
    }
    
private:
    int capacity, t;
    queue<int> q1;
    queue<int> q2;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
