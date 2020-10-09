//
//  main.cpp
//  LeetCode_696
//
//  Created by chx on 2020/8/10.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int length = (int)s.length();
        int result = 0;
        
        vector<int> memory;
        char curr = s[0];
        int start, end;
        start = end = 0;
        for (int i = 0; i < length; i++) {
            char temp = s[i];
            if (temp != curr) {
                curr = temp;
                if (!memory.empty()) result += min(memory.back(), i-start);
                memory.push_back(i-start);
                start = i;
            }
        }
        if (start != 0) result += min(memory.back(), length-start);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solve;
    string s = "0";
    int result = solve.countBinarySubstrings(s);
    return 0;
}
