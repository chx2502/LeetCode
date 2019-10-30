//
//  main.cpp
//  LeetCode_279_完全平方数
//
//  Created by chx on 2019/10/29.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    /*
     核心思路：
     动态规划，建立一个下标范围 [0, n] 的空数组 cache，对所有小于 n 的完全平方数 i，cache[i] = 1
     其他非完全平方数的空格由完全平方数算出。
     */
    vector<int> createSquares(int n) {
        int i = 1;
        vector<int> ret;
        while (true) {
            int temp = (int)pow(i++, 2);
            if (temp > n) return ret;
            else ret.push_back(temp);
        }
    }
    
    void calc(vector<int>& cache) {
        int current_square = 0;
        vector<int> squares;
        for (int i = 1; i < cache.size(); i++) {
            if (cache[i] == 1) {
                current_square = i;
                squares.push_back(current_square);
                continue;
            }
            else {
                int min = 0x7FFFFFFF;
                for (vector<int>::iterator iter = squares.end()-1; iter >= squares.begin(); iter--) {
                    int times = i / (*iter) + cache[i % (*iter)];
                    if (times < min) min = times;
                }
                cache[i] = min;
            }
        }
    }
    
    int numSquares(int n) {
        vector<int> sqaures = createSquares(n);
        vector<int> cache(n + 1, 0);
        for (auto i : sqaures) cache[i] = 1;
        calc(cache);
        return cache[n];
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int n = 13;
    Solution s;
    int result = s.numSquares(n);
    cout << result << endl;
    return 0;
}
