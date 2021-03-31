//
//  main.cpp
//  offer_14
//
//  Created by chx on 2021/3/30.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        const int MOD = 1e9+7;
        if (n <= 3) return n-1;
        long base = 3;
        int b = n % 3;
        long result = 1;
        for (int index = n/3 -1; index > 0; index >>= 1) {
            if (index & 1) {
                result *= base;
                result %= MOD;
            }
            base = (base * base) % MOD;
        }
        if (b == 0) result = result * 3 % MOD;
        if (b == 1) result = result * 4 % MOD;
        if (b == 2) result = result * 6 % MOD;
        return (int)result;
    }
    
    int fastPow(long base, int index) {
        long result = 1;
        const int MOD = 1e9+7;
        while (index) {
            if (index&1) {
                result *= base;
                result %= MOD;
                index--;
            } else {
                base *= base;
                base %= MOD;
                index >>= 1;
            }
        }
        return result % MOD;
    }
    
//    int cuttingRope(int n) {
//        vector<int> dp(n+1, 0);
//        dp[2] = 1;
//        for (int i = 3; i <= n; i++) {
//            for (int j = 2; j <= i; j++) {
//                dp[i] = max(dp[i], max(j * (i-j), j * dp[i-j]));
//            }
//        }
//        return dp[n];
//    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int result = s.cuttingRope(127);
    return 0;
}
