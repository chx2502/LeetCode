//
//  main.cpp
//  LeetCode_001
//
//  Created by 成鑫 on 2019/1/6.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        for (auto i = nums.cbegin(); i != nums.cend(); ++i) {
            for (auto j = i+1; j != nums.cend(); ++j) {
                if (*i + *j == target) {
                    ret.push_back(int(i - nums.cbegin()));
                    ret.push_back(int(j - nums.cbegin()));
                    return ret;
                }
            }
        }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
