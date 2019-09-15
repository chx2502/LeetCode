//
//  main.cpp
//  LeetCode_33_搜索旋转排序数组
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
        if (begin > end) return -1;
        if (begin == end) {
            if (target == nums[begin])
                return begin;
            else return -1;
        }
        int mid = (begin + end) / 2;
        if (target == nums[mid]) return mid;
        else if (target < nums[mid]) return binarySearch(nums, target, begin, mid-1);
        else return binarySearch(nums, target, mid+1, end);
    }
    int search(vector<int>& nums, int target) {
        int size = (int)nums.size();
        if (size == 0) return -1;
        int i, j;
        i = 0;
        while (i < size-1) {
            j = i+1;
            if (nums[i] > nums[j])
                break;
            i++;
        }
        if (i == size-1) return binarySearch(nums, target, 0, size-1);
        
        int leftResult, rightResult;
        leftResult = binarySearch(nums, target, 0, i);
        rightResult = binarySearch(nums, target, j, size-1);
        return leftResult > rightResult ? leftResult : rightResult;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> test = {3, 1};
    Solution s;
    int result = s.search(test, 1);
    return 0;
}
