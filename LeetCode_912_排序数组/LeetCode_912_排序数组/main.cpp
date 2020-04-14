//
//  main.cpp
//  LeetCode_912_排序数组
//
//  Created by chx on 2020/3/31.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
//    const int THRESHOLD = 8;
//    void insertSort(vector<int>& nums, int begin, int end) {
//        for (int i = begin+1; i <= end; ++i) {
//            int j = i;
//            while (j > 0 && nums[j] < nums[j-1]) {
//                swap(nums[j-1], nums[j]);
//                j--;
//            }
//        }
//    }
//
    int select3(vector<int>& nums, int begin, int end) {
        int mid = (begin + end) / 2;
        int a, b, c;
        a = nums[begin];
        b = nums[mid];
        c = nums[end];
        int temp1, temp2;
        temp1 = a < b ? begin : mid;
        temp2 = b < c ? mid : end;
        return nums[temp1] < nums[temp2] ? temp2 : temp1;
    }
    
    void quickSort(vector<int>& nums, int begin, int end) {
        if (begin >= end) return;
//        if (end - begin +1 < THRESHOLD) insertSort(nums, begin, end);
        
        int idx = nums[select3(nums, begin, end)];
        int pivot = nums[idx];
        swap(nums[begin], nums[idx]);
        int left, right;
        left = begin+1;
        right = end;
        while (left <= right) {
            if (nums[left] > pivot) {
                swap(nums[left], nums[right]);
                right--;
            } else ++left;

        }
        --left;
        swap(nums[begin], nums[left]);
        quickSort(nums, begin, left-1);
        quickSort(nums, left+1, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        int size = (int)nums.size();
        if (size > 1) quickSort(nums, 0, size-1);
        return nums;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {5, 1, 1, 2, 0, 0};
    s.sortArray(nums);
    return 0;
}
