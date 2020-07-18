//
//  main.cpp
//  LeetCode_38
//
//  Created by chx on 2020/7/18.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    
    string describe(string s) {
        int length = (int)s.length();
        string result = "";
        for (int i = 0; i < length; ++i) {
            int j = i+1;
            int count = 1;
            while (j <length && s[i] == s[j]) {
                i++;
                j++;
                count++;
            }
            result += to_string(count) + s[i];
        }
        return result;
    }
    
    string countAndSay(int n) {
        string result = "1";
        for (int i = 1; i < n; ++i) {
            result = describe(result);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string result = s.countAndSay(5);
    return 0;
}
