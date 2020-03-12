//
//  main.cpp
//  LeetCode_1071_字符串的最大公因子
//
//  Created by chx on 2020/3/12.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int length_1, length_2;
        length_1 = (int)str1.length();
        length_2 = (int)str2.length();
        int min = length_1 < length_2 ? length_1 : length_2;
        
        int devide = 1;
        for (int i = 2; i <= min; ++i)
            if (length_1 % i == 0 && length_2 % i == 0) devide = i;
        
        for (int i = 0; i < length_1; ++i)
            if (str1[i] != str2[i % length_2]) return "";
        return string(str1.begin(), str1.begin()+devide);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
