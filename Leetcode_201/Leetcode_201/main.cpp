//
//  main.cpp
//  Leetcode_201
//
//  Created by chx on 2020/8/23.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count = 0;
        while (m != n) {
            m = m >> 1;
            n = n >> 1;
            count++;
        }
        n = n << count;
        return n;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int result = s.rangeBitwiseAnd(0, INT_MAX);
    return 0;
}
