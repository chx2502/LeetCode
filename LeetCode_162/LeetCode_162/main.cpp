//
//  main.cpp
//  LeetCode_162
//
//  Created by chx on 2020/8/18.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    int bSearch(vector<int>& nums, int begin, int end) {
        if (begin == end) return begin;
        int mid = begin + (end-begin)/2;
        if (nums[mid] > nums[mid+1]) return bSearch(nums, begin, mid);
        else return bSearch(nums, mid+1, end);
    }
    
    int findPeakElement(vector<int>& nums) {
        int size = (int)nums.size();
        return bSearch(nums, 0, size-1);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    int result = s.findPeakElement(nums);
    return 0;
}
