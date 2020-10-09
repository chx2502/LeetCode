//
//  main.cpp
//  LeetCode_面试题62_ 圆圈中最后剩下的数字
//
//  Created by chx on 2020/3/30.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lastRemaining(int n, int m) {
        if (m == 1) return n-1;
        if (n == 1) return 0;
        return ( m%n + lastRemaining(n-1, m)) % n ;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int n, m;
    n = 5;
    m = 3;
    int res = s.lastRemaining(n, m);
    return 0;
}
