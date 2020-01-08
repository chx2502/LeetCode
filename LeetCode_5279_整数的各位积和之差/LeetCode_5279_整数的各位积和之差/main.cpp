//
//  main.cpp
//  LeetCode_5279_整数的各位积和之差
//
//  Created by chx on 2019/12/8.
//  Copyright © 2019 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 水题
    int subtractProductAndSum(int n) {
        int sum, multi;
        sum = 0;
        multi = 1;
        while (n != 0) {
            int temp = n % 10;
            sum += temp;
            multi *= temp;
            n /= 10;
        }
        return multi - sum;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
