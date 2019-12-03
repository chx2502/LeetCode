//
//  main.cpp
//  LeetCode_1221_分割平衡字符串
//
//  Created by chx on 2019/11/8.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    /*
     核心思路：
     利用栈实现，与栈顶相同即入栈，不同则出栈，
     每次栈空说明找到一个平衡串。
     */
    int balancedStringSplit(string s) {
        stack<char> stk;
        int ret = 0;
        for (auto c : s) {
            if (stk.empty()) {
                stk.push(c);
            } else {
                if (c != stk.top()) {
                    stk.pop();
                    if (stk.empty())
                        ret++;
                } else {
                    stk.push(c);
                }
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
