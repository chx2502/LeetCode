//
//  main.cpp
//  Leetcode_双周赛23_5362_构造 K 个回文字符串
//
//  Created by chx on 2020/4/4.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        int length = (int)s.length();
        if (length < k) return false;
        if (length == k) return true;
        vector<int> char_map(128, 0);
        for (auto &c : s) {
            char_map[c] += 1;
        }
        int odd_count = 0;
        int even_count = 0;
        for (auto count : char_map) {
            if (count == 0) continue;
            if (count & 1) {
                odd_count += 1;
                count -= 1;
                even_count += count / 2;
            } else even_count += count / 2;
        }
        if (odd_count + even_count < k) return false;
        if (odd_count > k) return false;
        else return true;
        
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string ss = "aaa";
    int k = 3;
    bool res = s.canConstruct(ss, k);
    return 0;
}
