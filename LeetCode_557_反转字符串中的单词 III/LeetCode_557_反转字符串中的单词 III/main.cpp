//
//  main.cpp
//  LeetCode_557_反转字符串中的单词 III
//
//  Created by chx on 2020/1/8.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        int length = (int)s.length();
        stack<char> stk;
        for (int i = 0; i < length; i++) {
            if (s[i] == ' ') {
                while(!stk.empty()) {
                    result.push_back(stk.top());
                    stk.pop();
                }
                result.push_back(' ');
            }
            else {
                stk.push(s[i]);
            }
        }
        while(!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "Let's take LeetCode contest";
    Solution sol;
    string result = sol.reverseWords(s);
    cout << result << endl;
    return 0;
}
