//
//  main.cpp
//  LeetCode_60_第k个排列
//
//  Created by chx on 2020/4/2.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // 参考题解，没想明白
    string getPermutation(int n, int k) {
        string nums = "";
        for (int i = 1; i <= n; ++i)
            nums += to_string(i);
        
        vector<int> fact(n, 1);
        for (int i = 1; i < n; ++i)
            fact[i] = fact[i-1] * i;
        k -= 1;
        string result;
        for (int i = n-1; i >= 0; --i) {
            int idx = k / fact[i];
            k -= idx * fact[i];
            result += nums[idx];
            nums.erase(nums.begin()+idx);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int n, k;
    n = 3;
    k = 3;
    string result = s.getPermutation(n, k);
    return 0;
}
