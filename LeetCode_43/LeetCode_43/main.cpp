//
//  main.cpp
//  LeetCode_43
//
//  Created by chx on 2020/8/13.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    string add(string num1, string num2) {
        if (num1 == "0") return num2;
        if (num2 == "0") return num1;
        
        string result = "";
        int len1 = (int)num1.length();
        int len2 = (int)num2.length();
        if (len1 < len2) {
            swap(len1, len2);
            swap(num1, num2);
        }
        num2 = string(len1-len2, '0') + num2;
        int overflow = 0;
        for (int i = len1-1; i >= 0; i--) {
            char a = num1[i];
            char b = num2[i];
            int temp = (a-'0') + (b-'0') + overflow;
            overflow = temp / 10;
            result = to_string(temp%10) + result;
        }
        if (overflow > 0) result = "1" + result;
        return result;
    }
    
    vector<int> trans(string s) {
        vector<int> result;
        for (auto c : s) {
            result.push_back(c-'0');
        }
        return result;
    }
    
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int len1 = (int)num1.length();
        int len2 = (int)num2.length();
        
        vector<int> v1 = trans(num1);
        vector<int> v2 = trans(num2);
        vector<int> vr(len1+len2-1, 0);
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                vr[i+j] += v1[i] * v2[j];
            }
        }
        string result = "0";
        int index = 0;
        for (int i = len1+len2-2; i >= 0; i--) {
            string curr = to_string(vr[i]);
            for (int j = 0; j < index; j++) {
                curr += "0";
            }
            index++;
            result = add(result, curr);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string num1 = "3";
    string num2 = "2";
    string res = s.multiply(num1, num2);
    return 0;
}
