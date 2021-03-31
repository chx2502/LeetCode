//
//  main.cpp
//  LeetCode_1806
//
//  Created by chx on 2021/3/29.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int reinitializePermutation(int n) {
        int pos = 1;
        int result = 0;
        do {
            pos = (pos & 1) ? (n/2) + (pos-1)/2 : pos/2;
            result++;
        } while (pos != 1);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int n = 8;
    int result = s.reinitializePermutation(n);
    return 0;
}
