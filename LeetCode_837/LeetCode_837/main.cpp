//
//  main.cpp
//  LeetCode_837
//
//  Created by chx on 2020/6/3.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     此解法超时
     **/
//    unordered_map<int, double> memory;
//    double game(int curr, int N, int K, int W) {
//        double result = 0.0;
//        if (curr >= K) {
//            memory[curr] = curr <= N ? 1.0 : 0.0;
//            return memory[curr];
//        }
//
//        if (memory.find(curr) != memory.end()) return memory[curr];
//
//        int end = N - curr >= W ? W : N-curr;
//        double weight = 1.0 / W;
//        for (int i = 1; i <= end; ++i) {
//            if (memory.find(curr+i) == memory.end())
//                memory[curr+i] = game(curr+i, N, K, W);
//            result += weight * memory[curr+i];
//        }
//        return result;
//    }
    
    double new21Game(int N, int K, int W) {
//        return game(0, N, K, W);
        vector<double> dp(K+W, 0.0);
        double sum = 0.0;
        for (int i = K; i <= N; ++i) {
            dp[i] = 1.0;
            sum += dp[i];
        }

        for (int i = K-1; i>= 0; --i) {
            dp[i] = sum / W;
            sum = sum - dp[i+W] + dp[i];
        }
        return dp[0];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int N, K, W;
    N = 9811;
    K = 8776;
    W = 1096;
    
    double result = s.new21Game(N, K, W);
    return 0;
}
