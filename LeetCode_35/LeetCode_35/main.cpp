//
//  main.cpp
//  LeetCode_35
//
//  Created by chx on 2020/7/17.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    int search(vector<int>& nums, int begin, int end, int target) {
        int mid = (begin + end) / 2;
        if (nums[mid] > target) {
            int new_end = mid-1;
            if (new_end < begin) return mid;
            else return search(nums, begin, new_end, target);
        }
        if (nums[mid] < target) {
            int new_begin = mid+1;
            if (new_begin > end) return end+1;
            else return search(nums, new_begin, end, target);
        }
        return mid;
    }
    
    int searchInsert(vector<int>& nums, int target) {
        int size = (int)nums.size();
        if (size == 0) return 0;
        
        return search(nums, 0, size-1, target);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    int result = s.searchInsert(nums, target);
    return 0;
}
