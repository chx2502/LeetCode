//
//  main.cpp
//  LeetCode_13_罗马数字转整数
//
//  Created by chx on 2020/2/25.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> M;
        M['I'] = 1;
        M['V'] = 5;
        M['X'] = 10;
        M['L'] = 50;
        M['C'] = 100;
        M['D'] = 500;
        M['M'] = 1000;
        int length = (int)s.length();
        int i, j, result;
        i = j = result = 0;
        result += M[s[0]];
        while (i++ < length-1) {
            j = i-1;
            char pre = s[j];
            char post = s[i];
            if (M[pre] < M[post]) result += M[post] - 2*M[pre];
            else result += M[post];
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
