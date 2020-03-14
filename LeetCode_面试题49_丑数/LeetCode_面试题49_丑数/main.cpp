//
//  main.cpp
//  LeetCode_面试题49_丑数
//
//  Created by chx on 2020/3/14.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        int p2, p3, p5;
        p2 = p3 = p5 = 0;
        for(int i = 1; i < n; ++i) {
            int a, b, c;
            a = dp[p2] * 2;
            b = dp[p3] * 3;
            c = dp[p5] * 5;
            dp[i] = min(min(a, b), min(b, c));
            if (dp[i] == a) p2++;
            if (dp[i] == b) p3++;
            if (dp[i] == c) p5++;
        }
        return dp[n-1];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int res = s.nthUglyNumber(11);
    return 0;
}
