//
//  main.cpp
//  LeetCode_153
//
//  Created by chx on 2020/8/26.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    int bSearch(int begin, int end, vector<int>& nums) {
        if (begin >= end) return nums[begin];
        int mid = begin + (end-begin)/2;
        
        if (nums[mid] < nums[begin] && nums[mid] < nums[end])
            return min(bSearch(begin, mid-1, nums), bSearch(mid, end, nums));
        if (nums[mid] > nums[end]) return bSearch(mid+1, end, nums);
        else return bSearch(begin, mid-1, nums);
    }
    
    int findMin(vector<int>& nums) {
        int size = (int)nums.size();
        return bSearch(0, size-1, nums);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {3, 1, 2};
    int result = s.findMin(nums);
    return 0;
}
