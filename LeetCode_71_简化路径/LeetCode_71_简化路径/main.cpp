//
//  main.cpp
//  LeetCode_71_简化路径
//
//  Created by 成鑫 on 2019/4/4.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        int point_count = 0;
        int len = (int)path.length();
        for (int i = 0; i < len; ++i) {
            if (isalpha(path[i])) {
                string s;
                do {
                    s = s + path[i++];
                } while (isalpha(path[i]));
                stk.push(s);
            }
            if (path[i] == '.') {
                point_count++;
                if (point_count == 2) {
                    i++;
                    if (path[i] == '.') {
                        stk.push("...");
                        point_count = 0;
                    } else if (!stk.empty()) stk.pop();
                    i--;
                    point_count = 0;
                }
            } else point_count = 0;
        }
        string ret;
        while (!stk.empty()) {
            string tmp = stk.top();
            stk.pop();
            ret = "/" + tmp + ret;
        }
        if (ret.length() == 0) ret = "/";
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    string path = "/...";
    Solution s;
    string result = s.simplifyPath(path);
    return 0;
}
