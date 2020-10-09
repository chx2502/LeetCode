//
//  main.cpp
//  LeetCode_面试题51_数组中的逆序对
//
//  Created by chx on 2020/4/24.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     在归并排序中插入计算逆序对的代码。
     具体计算方式为:
     当左边数组的第 i 个数被选中时，
     意味着他大于右边数组的 [0, j-1] 区间上的数
     贡献逆序对数量为 j 个。
     **/
    void merge(vector<int>& nums, int left, int mid, int right, int& count) {
        if (left >= right) return;
        vector<int> left_array = vector<int>(nums.begin()+left, nums.begin()+mid+1);
        vector<int> right_array = vector<int>(nums.begin()+mid+1, nums.begin()+right+1);
        
        int i, j, left_size, right_size;
        i = j = 0;
        left_size = mid-left+1;
        right_size = right-mid;
        int index = left;
        while (i < left_size && j < right_size) {
            if (left_array[i] > right_array[j])
                nums[index] = right_array[j++];
            else {
                nums[index] = left_array[i++];
                count += j;
            }
            index++;
        }
        while (i < left_size) {
            nums[index++] = left_array[i++];
            count += j;
        }
        while (j < right_size) nums[index++] = right_array[j++];
    }
    
    void mergeSort(vector<int>& nums, int begin, int end, int& count) {
        if (begin >= end) return;
        int mid = (begin + end) / 2;
        mergeSort(nums, begin, mid, count);
        mergeSort(nums, mid+1, end, count);
        merge(nums, begin, mid, end, count);
        return;
    }
    
    int reversePairs(vector<int>& nums) {
        int size = (int)nums.size();
        if (size == 0) return 0;
        
        int result = 0;
        mergeSort(nums, 0, size-1, result);
        
        return result;
    }
    /*
     常规暴力法超时
     **/
//    int reversePairs(vector<int>& nums) {
//        int size = (int)nums.size();
//        if (size == 0) return 0;
//
//        int result = 0;
//        for (int i = 0; i < size-1; ++i)
//            for (int j = i+1; j < size; ++j)
//                if (nums[j] < nums[i])
//                    result+= 1;
//        return result;
//    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    Solution s;
    int result = s.reversePairs(nums);
    return 0;
}
