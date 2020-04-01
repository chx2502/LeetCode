//
//  main.cpp
//  LeetCode_1111_有效括号的嵌套深度
//
//  Created by chx on 2020/4/1.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int length = (int)seq.length();
        vector<int> result;
        if (length == 0) return result;
        
        bool isCloseA, isCloseB;
        int countA, countB;
        isCloseA = isCloseB = false;
        countA = countB = 0;
        for (auto &c : seq) {
            if (c == '(') {
                if (countA <= countB) {
                    countA += 1;
                    result.push_back(0);
                    isCloseA = false;
                } else {
                    countB += 1;
                    result.push_back(1);
                    isCloseB = false;
                }
            }
            if (c == ')') {
                if (isCloseA) {
                    result.push_back(1);
                    countB -= 1;
                    if (countB == 0) isCloseB = true;
                } else {
                    result.push_back(0);
                    countA -= 1;
                    if (countA == 0) isCloseA = true;
                }
            }
        }
        return result;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
