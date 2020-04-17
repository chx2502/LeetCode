//
//  main.cpp
//  LeetCode_面试题17_打印从1到最大的n位数
//
//  Created by chx on 2020/4/17.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> result;
        if (n == 0) return result;
        int max = 0;
        while (n--) {
            max *= 10;
            max += 9;
        }
        for (int i = 1; i <= max; ++i) result.push_back(i);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
