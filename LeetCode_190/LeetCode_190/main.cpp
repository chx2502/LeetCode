//
//  main.cpp
//  LeetCode_190
//
//  Created by chx on 2021/3/29.
//

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res <<= 1;
            res |= (n&1);
            n >>= 1;
        }
        return res;
    }
    
//    double fastPow(double x, long long n) {
//        if (n == 0) return 1.0;
//
//        if (n < 0) return 1.0 / fastPow(x, -n-1);
//        if (n&1) return x * fastPow(x * x, n/2);
//        else return fastPow(x * x, n/2);
//    }
//
//    double myPow(double x, int n) {
//        return fastPow(x, (long long)n);
//    }
    
    double fastPow(double x, long long n) {
        if (n < 0) return 1.0 / fastPow(x, -n);
        
        double result = 1.0;
        while (n) {
            if (n&1) {
                result *= x;
                n--;
            } else {
                result *= result;
                n >>= 1;
            }
        }
        return result;
        stack<int> stk;
        stk.push(<#const value_type &__v#>)
    }
    
    
    
};

int main(int argc, const char * argv[]) {
    Solution s;
    int x = 2.0;
    int n = 2;
    double res = s.myPow(x, n);
    return 0;
}
