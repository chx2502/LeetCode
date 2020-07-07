//
//  main.cpp
//  LeetCode_58
//
//  Created by chx on 2020/7/7.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /*
     主要用到 string.find_last_of() 和 string.rfind()
     **/
    int lengthOfLastWord(string s) {
        unsigned long length = s.length();
        unsigned long start = s.find_last_of(" ");
        unsigned long end = length-1;
        if (length == 0) return 0;
        if (start == string::npos) return (int)length;
        
        if (start == length-1) {
            while(start > 0 && s[start-1] == ' ') start--;
            end = start;
            start = s.rfind(" ", start-1) + 1;
        }
        if (start == string::npos) start = 0;
        
        return start < end ? (int)(end - start) : 0;
    }
};

int main(int argc, const char * argv[]) {
    Solution solve;
    string s = " ";
    int result = solve.lengthOfLastWord(s);
    return 0;
}
