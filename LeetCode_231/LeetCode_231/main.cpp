//
//  main.cpp
//  LeetCode_231
//
//  Created by chx on 2020/9/14.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (!n) return false;
        if (n & 1) {
            if (n >> 1 == 0) return true;
            else return false;
        }
        while ((n&1) == 0) {
            n = n >> 1;
        }
        n = n >> 1;
        return n == 0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
