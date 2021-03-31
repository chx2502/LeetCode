//
//  main.cpp
//  LeetCode_191
//
//  Created by chx on 2020/7/6.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n) {
            result += 1;
            n &= n-1;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
