//
//  main.cpp
//  LeetCode_343
//
//  Created by chx on 2020/7/30.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, int> memory;
    
    int helper(int n) {
        if (memory.find(n) != memory.end()) return memory[n];
        int result = 0;
        for (int i = 1; i < n; i++) {
            int temp = max(i*(n-i), i*helper(n-i));
            result = result < temp ? temp : result;
        }
        memory[n] = result;
        return result;
    }
    
    int integerBreak(int n) {
        memory[1] = 1;
        memory[2] = 1;
        return helper(n);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    int result = s.integerBreak(25);
    return 0;
}
