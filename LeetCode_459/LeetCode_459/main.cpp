//
//  main.cpp
//  LeetCode_459
//
//  Created by chx on 2020/8/24.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /*
     最优解应为 KMP 算法。
     下面是枚举法
     **/
    bool repeatedSubstringPattern(string s) {
        int length = (int)s.length();
        for (int i = 1; i <= length/2; i++) {
            string substr = "";
            if (length % i == 0) {
                substr = s.substr(0, i);
                int start = i;
                bool flag = true;
                while (start < length) {
                    if (substr.compare(s.substr(start, substr.length())) != 0) {
                        flag = false;
                        break;
                    }
                    start += substr.length();
                }
                if (flag) return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution solve;
    string s = "abcabcabcabc";
    bool result = solve.repeatedSubstringPattern(s);
    return 0;
}
