//
//  main.cpp
//  LeetCode_32
//
//  Created by chx on 2020/7/4.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int length = (int)s.length();
        if (length == 0) return 0;
        
        stack<int> stk;
        stk.push(-1);
        int result = 0;
        
        for (int i = 0; i < length; ++i) {
            const char c = s[i];
            if (c == '(') {
                stk.push(i);
                continue;
            }
            stk.pop();
            if (stk.size() == 0) stk.push(i);
            else {
                int curr = i - stk.top();
                result = result < curr ? curr : result;
            }
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solve;
    string s = ")()())";
    int result = solve.longestValidParentheses(s);
    
    return 0;
}
