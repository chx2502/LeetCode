//
//  main.cpp
//  LeetCode_259
//
//  Created by chx on 2021/3/1.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
//    int threeSumSmaller(vector<int>& nums, int target) {
//        int size = (int)nums.size();
//
//        int result = 0;
//        for (int i = 0; i < size; i++) {
//            for (int j = i+1; j < size; j++) {
//                for (int k = j+1; k < size; k++) {
//                    if (nums[i] + nums[j] + nums[k] < target) result++;
//                }
//            }
//        }
//        return result;
//    }
    
    int binarySearch(int begin, vector<int>& nums, int target) {
        int left = begin;
        int right = (int)nums.size()-1;
        
        while (left < right) {
            int mid = (left+right+1) / 2;
            if (nums[mid] < target) left = mid;
            else right = mid-1;
        }
        return left;
    }
    
    int twoSumSmaller(vector<int>& nums, int begin, int target) {
        int size = (int)nums.size();
        
        int result = 0;
        for (int i = begin; i < size; i++) {
            result += binarySearch(i, nums, target-nums[i]) - i;
        }
        return result;
    }
    
    int threeSumSmaller(vector<int>& nums, int target) {
        int size = (int)nums.size();
        int result = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size-2; i++) {
            result += twoSumSmaller(nums, i+1, target-nums[i]);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {-2, 0, 1, 3};
    int result = s.threeSumSmaller(nums, 2);
    return 0;
}
