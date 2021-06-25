//
//  main.cpp
//  LeetCode_633
//
//  Created by chx on 2021/4/28.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

typedef unsigned long long ULL;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int size = (int)sqrt(c);
//        for (int i = 0; i <= size; i++) {
//            int j = (int)sqrt(c-i*i);
//            if (i * i + j * j == c) return true;
//        }
        int left, right;
        left = 0;
        right = size;
        while (left <= right) {
            unsigned long long temp = left*left + right*right;
            if (temp == c) return true;
            if (temp > c) right--;
            if (temp < c) left++;
            
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> cases = {0, 1, 2, 3, 4, 5, 100, INT32_MAX};
    for (int i = 0; i < cases.size(); i++) {
        bool res = s.judgeSquareSum(cases[i]);
        if (res) cout << "true" << endl;
        else cout << "false" << endl;
    }
    return 0;
}
