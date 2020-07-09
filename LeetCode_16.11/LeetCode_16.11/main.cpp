//
//  main.cpp
//  LeetCode_16.11
//
//  Created by chx on 2020/7/8.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> result;
        if (k == 0) return result;
        
        result.push_back(shorter * k);
        int bias = longer-shorter;
        if (bias == 0) return result;
        
        for (int i = 0; i < k; ++i) {
            result.push_back(bias+result.back());
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int shorter = 1;
    int longer = 2;
    int k = 4;
    vector<int> result = s.divingBoard(shorter, longer, k);
    return 0;
}
