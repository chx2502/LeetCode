//
//  main.cpp
//  LeetCode_67
//
//  Created by chx on 2020/7/11.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int length_a = (int)a.length();
        int length_b = (int)b.length();
        if (length_a == 0) return b;
        if (length_b == 0) return a;
        
        int length = length_a > length_b ? length_a :length_b;
        if (length_a > length_b) b = string(length_a-length_b, '0') + b;
        if (length_a < length_b) a = string(length_b-length_a, '0') + a;
        
        string result = "";
        int sum = 0;
        int ca = 0;
        for (int i = length-1; i >= 0; --i) {
            sum = a[i] - '0' + b[i] - '0' + ca;
            result.push_back(sum % 2 + '0');
            ca = sum > 1 ? 1 : 0;
        }
        if (ca == 1) result.push_back('1');
        reverse(result.begin(), result.end());
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string a = "11";
    string b = "11";
    string result = s.addBinary(a, b);
    return 0;
}
