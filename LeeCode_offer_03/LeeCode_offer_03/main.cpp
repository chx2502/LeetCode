//
//  main.cpp
//  LeeCode_offer_03
//
//  Created by chx on 2020/7/17.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> num_set;
        int result = -1;
        for (auto num : nums) {
            if (num_set.find(num) == num_set.end()) num_set.insert(num);
            else {
                result = num;
                break;
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
