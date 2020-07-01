//
//  main.cpp
//  LeetCode_171
//
//  Created by chx on 2020/7/1.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int bias = 'A' - 1;
        vector<int> array;
        int count = 0;
        for (auto c : s) {
            array.push_back(c - bias);
            count += 1;
        }
        int base = 26;
        long curr = 1;
        int result = 0;
        for (int i = count-1; i >= 0; --i) {
            result += array[i] * curr;
            curr *= base;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
