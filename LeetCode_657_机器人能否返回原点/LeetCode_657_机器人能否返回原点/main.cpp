//
//  main.cpp
//  LeetCode_657_机器人能否返回原点
//
//  Created by chx on 2019/11/14.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        stack<char> horizontal;
        stack<char> vertical;
        
        for (auto c : moves) {
            if (c == 'U' || c == 'D') {
                if (vertical.empty()) vertical.push(c);
                else {
                    if (c != vertical.top()) vertical.pop();
                    else vertical.push(c);
                }
            }
            if (c == 'L' || c == 'R') {
                if (horizontal.empty()) horizontal.push(c);
                else {
                    if (c != horizontal.top()) horizontal.pop();
                    else horizontal.push(c);
                }
            }
        }
        if (horizontal.empty() && vertical.empty()) return true;
        else return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
