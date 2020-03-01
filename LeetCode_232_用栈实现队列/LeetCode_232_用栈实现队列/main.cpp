//
//  main.cpp
//  LeetCode_232_用栈实现队列
//
//  Created by chx on 2020/3/1.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> stk_1;
    stack<int> stk_2;
    int capacity;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        capacity = 0;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stk_1.push(x);
        capacity++;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int result = peek();
        stk_2.pop();
        capacity--;
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        if (stk_2.empty()) {
            while (!stk_1.empty()) {
                stk_2.push(stk_1.top());
                stk_1.pop();
            }
        }
        return stk_2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return capacity == 0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
