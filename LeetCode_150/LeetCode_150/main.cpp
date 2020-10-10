//
//  main.cpp
//  LeetCode_150
//
//  Created by chx on 2020/10/9.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int size = (int)tokens.size();
        if (size == 0) return 0;
        stack<string> stk;
        for (auto &s : tokens) {
            int mark = 0;
            if (s.compare("+") == 0) mark = 1;
            if (s.compare("-") == 0) mark = 2;
            if (s.compare("*") == 0) mark = 3;
            if (s.compare("/") == 0) mark = 4;
            
            if (mark) {
                int a = stoi(stk.top());
                stk.pop();
                int b = stoi(stk.top());
                stk.pop();
                if (mark == 1) stk.push(to_string(b+a));
                if (mark == 2) stk.push(to_string(b-a));
                if (mark == 3) stk.push(to_string(b*a));
                if (mark == 4) stk.push(to_string(b/a));
            } else stk.push(s);
        }
        return stoi(stk.top());
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> tokens = {"4","13","5","/","+"};
    Solution s;
    int result = s.evalRPN(tokens);
    return 0;
}
