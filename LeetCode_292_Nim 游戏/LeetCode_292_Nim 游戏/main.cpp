//
//  main.cpp
//  LeetCode_292_Nim 游戏
//
//  Created by chx on 2019/12/5.
//  Copyright © 2019 __Ninja__. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return (n % 4) != 0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
