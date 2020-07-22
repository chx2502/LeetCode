//
//  main.cpp
//  LeetCode_154
//
//  Created by chx on 2020/7/22.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 递归法
    int find(vector<int>& nums, int begin, int end) {
        if (begin == end) return begin;
        if (begin == end-1) return nums[begin] < nums[end] ? begin : end;
        int mid = (begin + end) / 2;
        
        int l, m, r;
        l = nums[begin];
        m = nums[mid];
        r = nums[end];

        if (m < r)
            return find(nums, begin, mid);
        if (m > r)
            return find(nums, mid, end);
        return find(nums, begin, end-1);
    }
    
    // 非递归
    int findMin(vector<int>& nums) {
        int size = (int)nums.size();
        int begin, end, mid;
        begin = 0;
        end = size-1;
        
        while (begin < end) {
            mid = (begin + end) / 2;
            if (nums[mid] < nums[end]) end = mid;
            else if (nums[mid] > nums[end]) begin = mid+1;
            else end--;
        }
        return nums[begin];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {3, 3, 1, 3};
    int result = s.findMin(nums);
    return 0;
}
