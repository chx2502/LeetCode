//
//  main.cpp
//  LeetCode_155
//
//  Created by chx on 2020/8/18.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        curr_min = INT_MAX;
    }
    
    void push(int x) {
        container.push(x);
        if (x <= curr_min) {
            curr_min = x;
            memory.push(x);
        }
    }
    
    void pop() {
        int num = container.top();
        container.pop();
        if (num == curr_min) {
            memory.pop();
            if (!memory.empty()) curr_min = memory.top();
            else curr_min = INT_MAX;
        }
    }
    
    int top() {
        if (!container.empty()) return container.top();
        else return INT_MAX;
    }
    
    int getMin() {
        return curr_min;
    }
private:
    int curr_min;
    stack<int> container;
    stack<int> memory;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
