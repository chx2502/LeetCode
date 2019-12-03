//
//  main.cpp
//  LeetCode_728_自除数
//
//  Created by chx on 2019/12/1.
//  Copyright © 2019 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     水题
     **/
    bool isSelfDividingNumber(int num) {
        int temp = num;
        while(temp > 0) {
            int divid = temp%10;
            temp /= 10;
            if (divid == 1) continue;
            if (divid == 0) return false;
            if (num % divid != 0) return false;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;
        for (int num = left; num <= right; num++) {
            if (isSelfDividingNumber(num)) ret.push_back(num);
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
