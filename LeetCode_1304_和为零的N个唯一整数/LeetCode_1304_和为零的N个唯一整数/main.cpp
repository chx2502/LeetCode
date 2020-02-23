//
//  main.cpp
//  LeetCode_1304_和为零的N个唯一整数
//
//  Created by chx on 2020/2/23.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        if (n % 2) result.push_back(0);
        n /= 2;
        while (n) {
            result.push_back(0-n);
            result.push_back(0+n);
            n--;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
