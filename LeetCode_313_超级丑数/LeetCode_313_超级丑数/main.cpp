//
//  main.cpp
//  LeetCode_313_超级丑数
//
//  Created by 成鑫 on 2019/7/14.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

#define INF 2147483647

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = (int)primes.size();
        vector<int> res;
        res.push_back(1);
        vector<int> index(k, 0);
        while (res.size() < n) {
            int min = INF;
            for (int i = 0; i < k; i++) {
                int idx = index[i];
                int tmp = res[idx] * primes[i];
                if (tmp < min) min = tmp;
            }
            for (int i = 0; i < k; i++) {
                int idx = index[i];
                int tmp = res[idx] * primes[i];
                if (tmp == min) index[i]++;
            }
            res.push_back(min);
        }
        return res[n-1];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
