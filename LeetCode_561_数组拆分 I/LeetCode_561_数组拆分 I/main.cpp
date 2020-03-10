//
//  main.cpp
//  LeetCode_561_数组拆分 I
//
//  Created by chx on 2020/3/10.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int size = (int)nums.size();
        sort(nums.begin(), nums.end(), less<int>());
        int result = 0;
        for (int i = 0; i < size-1; i+=2) {
            result += nums[i];
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
