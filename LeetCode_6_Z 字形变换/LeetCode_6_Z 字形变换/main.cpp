//
//  main.cpp
//  LeetCode_6_Z 字形变换
//
//  Created by chx on 2020/2/25.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     此解法效率较低，时间复杂度为 O((numRows+1) * N), N 为字符串长度。
     为每个字符分配一个下标，下标范围为[0, numRows)，
     返回字符串为：
     "所有下标为 0 的字符" + "所有下标为 1 的字符" + ... + "所有下标为 numRows-1 的字符"
     **/
    string convert(string s, int numRows) {
        int length = (int)s.length();
        if (length <= numRows || numRows == 1) return s;
        string result = "";
        vector<int> charMap(length, 0);
        int count = 0;
        bool increase = true;
        for (auto &i : charMap) {
            if (increase) {
                i = count++;
                if (count == numRows) {
                    count--;
                    increase = false;
                }
            } else {
                i = --count;
                if (count == 0) {
                    count++;
                    increase = true;
                }
            }
        }
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < length; ++j)
                if (charMap[j] == i)
                    result.push_back(s[j]);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solu;
    string s = "PAYPALISHIRING";
    solu.convert(s, 3);
    return 0;
}
