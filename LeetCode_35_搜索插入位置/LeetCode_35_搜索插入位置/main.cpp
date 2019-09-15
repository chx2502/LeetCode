//
//  main.cpp
//  LeetCode_35_搜索插入位置
//
//  Created by 成鑫 on 2019/8/7.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int begin, int end) {
        if (begin >= end) return begin;
        if (begin == end) {
            if (nums[begin] >= target) return begin;
            else return begin+1;
        }
        int mid;
        mid = (begin + end) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) return binarySearch(nums, target, begin, mid-1);
        else return binarySearch(nums, target, mid+1, end);
    }
    int searchInsert(vector<int>& nums, int target) {
        int size = (int)nums.size();
        if (size == 0) return 0;
        return binarySearch(nums, target, 0, size-1);
    }
};

int main(int argc, const char * argv[]) {
    vector<int> test = {3, 5, 7, 9, 10};
    Solution s;
    int result = s.searchInsert(test, 8);
    return 0;
}
