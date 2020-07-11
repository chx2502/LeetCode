//
//  main.cpp
//  LeetCode_66
//
//  Created by chx on 2020/7/11.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void plus(vector<int>& digits, int pos) {
        if (pos < 0) {
            digits.insert(digits.begin(), 1);
        } else {
            digits[pos] += 1;
            if (digits[pos] == 10) {
                digits[pos] = 0;
                plus(digits, pos-1);
            }
        }
        return;
    }

    vector<int> plusOne(vector<int>& digits) {
        int size = (int)digits.size();
        if (size) plus(digits, size-1);
        return digits;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    return 0;
}
