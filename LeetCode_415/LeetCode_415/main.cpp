//
//  main.cpp
//  LeetCode_415
//
//  Created by chx on 2020/8/3.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    
    vector<int> add(char digit1, char digit2, int bias) {
        int a = digit1 - '0';
        int b = digit2 - '0';
        int sum = a + b + bias;
        int remain = 0;
        if (sum > 9) remain = 1;
        int result = sum % 10;
        return {result, remain};
    }
    
    string addStrings(string num1, string num2) {
        int len1 = (int)num1.length();
        int len2 = (int)num2.length();
        if (len1 == 0 || len2 == 0)
            return len1 == 0 ? num1 : num2;
        string result = "";
        if (len1 < len2) {
            swap(num1, num2);
            swap(len1, len2);
        }
        num2 = string(len1 - len2, '0') + num2;
        int bias = 0;
        for (int i = len1-1; i >= 0; i--) {
            vector<int> temp = add(num1[i], num2[i], bias);
            char digit = temp[0] + '0';
            result.push_back(digit);
            bias = temp[1];
        }
        if (bias) result.push_back('1');
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string num1 = "9";
    string num2 = "99";
    string result = s.addStrings(num1, num2);
    return 0;
}
