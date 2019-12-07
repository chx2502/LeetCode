//
//  main.cpp
//  LeetCode_942_增减字符串匹配
//
//  Created by chx on 2019/12/5.
//  Copyright © 2019 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string S) {
        unsigned long length = S.size();
        vector<int> ret;
        deque<int> dq;
        for (int i = 0; i <= length; i++) {
            dq.push_back(i);
        }
        if (length == 0) return ret;
        for (int i = 0; i < length; i++) {
            if (S[i] == 'D') {
                ret.push_back(dq.back());
                dq.pop_back();
            }
            if (S[i] == 'I') {
                ret.push_back(dq.front());
                dq.pop_front();
            }
        }
        ret.push_back(dq.front());
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
