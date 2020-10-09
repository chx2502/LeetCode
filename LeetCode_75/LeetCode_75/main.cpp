//
//  main.cpp
//  LeetCode_75
//
//  Created by chx on 2020/9/16.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> M;
        for (auto & num : nums) M[num]++;
        int start = 0;
        for (int i = 0; i < 3; i++) {
            int count = M[i];
            for (int j = 0; j < count; j++) nums[start++] = i;
        }
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
