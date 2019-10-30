//
//  main.cpp
//  LeetCode_20_有效的括号
//
//  Created by chx on 2019/10/26.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unsigned long length = s.size();
        if (length == 0) return true;
        if (length % 2 > 0) return false;
        stack<char> brace_stack;

        int count = 0;
        for (auto brace : s) {
            if (brace == '(' || brace == '[' || brace == '{') {
                brace_stack.push(brace);
                count++;
            }
            if (brace == ')' || brace == ']' || brace == '}') {
                if (brace_stack.empty()) return false;
                char temp = brace_stack.top();
                if (abs(brace - temp) > 2) return false;
                brace_stack.pop();
                count--;
            }
        }
        return count == 0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    string str = "()[]{}";
//    bool result = s.isValid(str);
//    cout << result << endl;
    for (int i = 0; i < str.size(); i++) {
        int j = i+1;
        cout << str[j] - str[i] << endl;
    }
    return 0;
}
