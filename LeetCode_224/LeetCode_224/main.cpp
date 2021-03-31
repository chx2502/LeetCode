//
//  main.cpp
//  LeetCode_224
//
//  Created by chx on 2021/3/10.
//

#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    
    int noBraceCalculate(string s) {
        string currrNum;
        stack<int> nums;
        vector<char> ops;
        for (auto &c : s) {
            if (c >= '0' && c <= '9') {
                currrNum.push_back(c);
            } else {
                if (c == ' ') continue;
                ops.push_back(c);
                nums.push(stoi(currrNum));
                currrNum = "";
            }
        }
        if (currrNum.length()) nums.push(stoi(currrNum));
        reverse(ops.begin(), ops.end());
        for (auto &op : ops) {
            int a = nums.top();
            nums.pop();
            int b = nums.top();
            nums.pop();

            int res = (op == '+') ? a + b : a - b;
            nums.push(res);
        }
        return nums.top();
    }
    
    int calculate(string s) {
        int length = (int)s.length();
        stack<char> stk;
        for (int i = 0; i < length; i++) {
            if (s[i] == ')') {
                string sub = "";
                while (!stk.empty() && stk.top() != '(') {
                    sub.insert(sub.begin(), stk.top());
                    stk.pop();
                }
                stk.pop();
                string res = to_string(noBraceCalculate(sub));
                for (auto &r : res) stk.push(r);
            } else stk.push(s[i]);
        }
        string end = "";
        while (!stk.empty()) {
            end.insert(end.begin(), stk.top());
            stk.pop();
        }
        return noBraceCalculate(end);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string str = "(1+(4+5+2)-3)+(6+8)";
    int result = s.calculate(str);
    return 0;
}
