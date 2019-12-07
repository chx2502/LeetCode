//
//  main.cpp
//  LeetCode_1025_除数博弈
//
//  Created by chx on 2019/12/6.
//  Copyright © 2019 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     动态规划：
     对于 i，若 j 能被 i 整除 且 i-j 的结果为 false，则 N 为 true
     找到能使 i 为 true 的 j 即开始找下一个 i，当 i == N 时结束
     **/
    bool divisorGame(int N) {
        vector<bool> result_arr(N+1, false);
        int i = 1;
        while (i++ <= N) {
            for (int j = 1; j < i; j++) {
                if (i % j == 0) {
                    result_arr[i] = !result_arr[i-j];
                    if (result_arr[i]) break;
                }
            }
            if (result_arr[i] == true)
                continue;
        }
        return result_arr[N];
    }
    /*
     取巧做法
     **/
//    bool divisorGame(int N) {
//        return (N % 2) == 0;
//    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int N = 10;
    bool result = s.divisorGame(N);
    return 0;
}
