//
//  main.cpp
//  LeetCode_050
//
//  Created by 成鑫 on 2019/1/6.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>

using namespace std;

// 将 x^n 转化为 (x^2)^n/2 或 x*[(x^2)^(n-1)/2]
// 递归调用myPow，将乘法执行次数减少到O(logN)级别
// 注意对边界的处理，指数 n 的范围为[-2^16, 2^16-1]，若 n 取下界，-n会溢出，需要单独处理
// LeetCode 执行耗时 8ms

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (n > 0) {
            if (n == 1) return x;
            if (x == 1.0) return x;
            if (n % 2 == 0) {
                if (x == -1.0) return -x;
                else return myPow(x * x, n/2);
            }
            if (n % 2 == 1) {
                if (x == -1.0) return x;
                else return x * myPow(x * x, (n-1)/2);
            }
        }
        if (n < 0) {
            if (n == -2147483648) {
                n += 1;
                return x * myPow(1/x, -n);
            }
            else return myPow(1/x, -n);
        }
        else return 1.0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution *pSolution = new Solution();
    pSolution->myPow(1.0, -2147483648);
    return 0;
}
