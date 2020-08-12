//
//  main.cpp
//  LeetCode_71
//
//  Created by chx on 2020/8/12.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    
    void process(string curr, stack<string>& stk) {
        if (curr == ".") return;
        if (curr == ".." && !stk.empty()) stk.pop();
        if (curr != "..") stk.push("/"+curr);
    }
    
    string simplifyPath(string path) {
        int length = (int)path.length();
        if (length == 0) return "/";
        stack<string> stk;
        string curr = "";
        for (int i = 0; i < length; i++) {
            if (path[i] == '/') {
                if (curr.length()) {
                    process(curr, stk);
                    curr = "";
                }
            } else {
                curr += path[i];
            }
        }
        if (curr.length()) process(curr, stk);
        if (stk.empty()) return "/";
        string result = "";
        while (!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string path = "/a//b////c/d//././/..";
    string result = s.simplifyPath(path);
    return 0;
}
