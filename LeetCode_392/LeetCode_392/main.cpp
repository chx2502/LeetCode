//
//  main.cpp
//  LeetCode_392
//
//  Created by chx on 2020/7/27.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int t_length = (int)t.length();
        int s_length = (int)s.length();
        if (s_length == 0) return true;
        int curr = 0;
        for (int i = 0; i < t_length; i++) {
            if (t[i] == s[curr]) curr++;
            if (curr == s_length) return true;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
