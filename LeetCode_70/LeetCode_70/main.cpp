//
//  main.cpp
//  LeetCode_70
//
//  Created by chx on 2020/7/14.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n < 0) return 0;
        if (n <= 1) return 1;
        static unordered_map<int, int> memory;
        if (memory.find(n) != memory.end()) return memory[n];
        else {
            memory[n] = climbStairs(n-1) + climbStairs(n-2);
        }
        return memory[n];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
