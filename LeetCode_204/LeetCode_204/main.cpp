//
//  main.cpp
//  LeetCode_204
//
//  Created by chx on 2020/8/24.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     筛法求素数
     **/
    int countPrimes(int n) {
        if (n < 2) return 0;
        char memory[n];
        memset(memory, 1, n);
        memory[0] = memory[1] = 0;
        
        int count = n - 2;
        for (int i = 2; i <= n/2; i++) {
            if (memory[i]) {
                int j = 2;
                while (i*j < n) {
                    if (memory[i*j]) count--;
                    memory[i*j] = 0;
                    j++;
                }
            }
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int result = s.countPrimes(5);
    return 0;
}
