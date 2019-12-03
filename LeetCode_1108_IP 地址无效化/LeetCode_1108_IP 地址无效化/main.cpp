//
//  main.cpp
//  LeetCode_1108_IP 地址无效化
//
//  Created by chx on 2019/11/7.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /*
     太简单了没啥好说的
     */
    string defangIPaddr(string address) {
        string ret;
        for (auto c : address) {
            if (c == '.') ret.append("[.]");
            else ret.push_back(c);
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
