//
//  main.cpp
//  LeetCode_81_搜索旋转排序数组 II
//
//  Created by 成鑫 on 2019/1/12.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 找到数组的旋转点
    int findMidPoint (vector<int>& nums) {
        for (auto i = nums.cbegin(); i != nums.cend(); ++i) {
            if (i == nums.cend()-1) return 0;   // 未旋转，返回0；
            auto j = i + 1;
            if (*i > *j) return int(i - nums.cbegin() + 1); // 找到旋转点 i，返回 i 的右侧，用来处理 size=2 的情况
        }
        return 0;
    }
    
    // 二分查找
    bool bSearch(vector<int>& nums, int target, int left, int right) {
        if (left >= right) {
            if (nums[left] == target) return true;
            else return false;
        }
        int mid = (left + right) / 2;
        if (nums[mid] < target) return bSearch(nums, target, mid+1, right);
        if (nums[mid] > target) return bSearch(nums, target, left, mid-1);
        if (nums[mid] == target) return true;
        else return false;
    }
    
    // findMidPoint 找到旋转点，然后对旋转点两边进行二分查找，注意对空数组的处理和对 size=2 的数组的旋转点处理。
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;
        int mid = findMidPoint(nums);
        if (mid == 0) return bSearch(nums, target, 0, int(nums.size()-1));
        else return (bSearch(nums, target, 0, mid-1) || bSearch(nums, target, mid, int(nums.size()-1)));
    }
};

int main(int argc, const char * argv[]) {
    int target = 1;
    vector<int> nums = {3, 1};
    Solution s;
    bool result = s.search(nums, target);
    return 0;
}
