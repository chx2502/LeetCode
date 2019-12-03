//
//  main.cpp
//  LeetCode_709_转换成小写字母
//
//  Created by chx on 2019/11/13.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        string ret;
        for (auto c : str) {
            if ('A' <= c && c <= 'Z')
                c += 32;
            ret.push_back(c);
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    string str = "Hello";
    string result = s.toLowerCase(str);
    cout << result << endl;
    cout << (int)'a' << ' ' << (int)'z' << ' ' << (int)'A' << ' ' << (int)'Z' << endl;
    return 0;
}
