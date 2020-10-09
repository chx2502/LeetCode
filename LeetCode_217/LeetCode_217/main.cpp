//
//  main.cpp
//  LeetCode_217
//
//  Created by chx on 2020/9/14.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> num_set;
        for (auto &num : nums) {
            if (num_set.count(num)) return true;
            num_set.insert(num);
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
