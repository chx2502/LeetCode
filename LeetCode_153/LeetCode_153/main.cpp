//
//  main.cpp
//  LeetCode_153
//
//  Created by chx on 2021/4/8.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bSearch(int begin, int end, vector<int>& nums) {
        if (begin > end) return -1;
        while (begin < end) {
            int mid = begin + (end-begin) / 2;
            if (nums[mid] > nums[end]) begin = mid+1;
            else end = mid;
        }
        return nums[begin];
    }
    
    int findMin(vector<int>& nums) {
        int size = (int)nums.size();
        return bSearch(0, size-1, nums);
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {11,13,15,17};
    Solution s;
    
    int res = s.findMin(nums);
    return 0;
}
