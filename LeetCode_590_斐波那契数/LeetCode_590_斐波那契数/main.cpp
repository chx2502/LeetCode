//
//  main.cpp
//  LeetCode_590_斐波那契数
//
//  Created by chx on 2020/2/29.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     递归实现
     **/
//    int fib(int N) {
//        if (N == 0) return 0;
//        if (N == 1) return 1;
//        return fib(N-1) + fib(N-2);
//    }
    /*
     数组实现
     **/
    int fib(int N) {
        vector<int> array(N+1, 0);
        if (N > 0) array[1] = 1;
        for (int i = 2; i <= N; ++i) {
            array[i] = array[i-1] + array[i-2];
        }
        return array[N];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int result = s.fib(0);
    return 0;
}
