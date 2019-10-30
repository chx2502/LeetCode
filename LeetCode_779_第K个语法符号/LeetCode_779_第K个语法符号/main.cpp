//
//  main.cpp
//  LeetCode_779_第K个语法符号
//
//  Created by chx on 2019/10/22.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    /*
     核心思路：
     第 N 行 = （N-1 行）后面接 (N-1 行) 按位取反
     第 N 行的 第 2^(N-2)+1 到 2^(N-1) 位与第 N 行的第 1 到 2^(N-2) 位一一对应且互异
     若 K > 2^(N-2), 则结果为第 N-1 行第 K - 2^(N-2) 位取反
     若 K <= 2^(N-2)，则结果为第 N-1 行第 K 位
     按此思路递归直到 K = {1, 2}
     */
    int kthGrammar(int N, int K) {
        if (K == 1) return 0;
        else if (K == 2) return 1;
        else {
            int bias = (int)pow(2, N-2);
            if (K > bias) return 1 - kthGrammar(N-1, K-bias);
            else return kthGrammar(N-1, K);
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int result = s.kthGrammar(4, 3);
    cout << result << endl;
    return 0;
}
