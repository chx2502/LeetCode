//
//  main.cpp
//  LeetCode_31
//
//  Created by chx on 2020/9/16.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = (int)nums.size();
        if (size == 0) return;
        
        int i, j;
        j = size-1;
        i = j-1;
        
        while (i >= 0) {
            if (nums[i] < nums[j]) break;
            else {
                i--; j--;
            }
        }
        if (i >= 0) {
            int k = size-1;
            while(k >= j) {
                if (nums[i] < nums[k]) break;
                else k--;
            }
            swap(nums[i], nums[k]);
        }
        reverse(nums.begin()+j, nums.end());
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 3, 2};
    Solution s;
    s.nextPermutation(nums);
    return 0;
}
