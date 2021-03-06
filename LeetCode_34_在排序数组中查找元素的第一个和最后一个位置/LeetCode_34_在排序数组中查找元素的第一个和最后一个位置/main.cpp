//
//  main.cpp
//  LeetCode_34_在排序数组中查找元素的第一个和最后一个位置
//
//  Created by chx on 2020/2/25.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     二分查找到 target 后，向左右两边搜索起点和终点。
     若查找失败则直接返回 {-1, -1}
     **/
//    vector<int> searchRange(vector<int>& nums, int target) {
//        int length = (int)nums.size();
//        if (length == 0) return vector<int>(2, -1);
//        vector<int> result;
//
//        int left, right, mid;
//        left = 0;
//        right = length-1;
//        mid = (left + right) / 2;
//
//        while (nums[mid] != target && right >= left) {
//            if (nums[mid] > target) right = mid-1;
//            else left = mid+1;
//            mid = (left + right) / 2;
//        }
//
//        if (nums[mid] == target) {
//            int i, j;
//            i = j = mid;
//            while (i > 0 && nums[i-1] == target) i--;
//            while (j < length-1 && nums[j+1] == target) j++;
//            result.push_back(i);
//            result.push_back(j);
//            return result;
//        } else return vector<int>(2, -1);
//    }
    
    int binarySearch(vector<int>& nums, int target, bool lower) {
        int left, right;
        left = 0;
        right = (int)nums.size()-1;
        
        int result = (int)nums.size();
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid-1;
                result = mid;
            } else {
                left = mid+1;
            }
        }
        return result;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        if (nums.empty()) return result;
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false) - 1;
        if (left <= right && right < nums.size() && nums[left] == target && nums[right] == target) result = {left, right};
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1};
    vector<int> result = s.searchRange(nums, 1);
    return 0;
}
