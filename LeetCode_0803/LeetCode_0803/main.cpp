//
//  main.cpp
//  LeetCode_0803
//
//  Created by chx on 2020/7/31.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    const int MAX = 0x3f3f3f3f;
    int bSearch(vector<int>& nums, int begin, int end) {
        if (end < begin) return -1;
        int mid = (end-begin) / 2 + begin;

        int l = bSearch(nums, begin, mid-1);
        if (l != -1) return l;
        else if (nums[mid] == mid) return mid;
        return bSearch(nums, mid+1, end);
    }
        
    int findMagicIndex(vector<int>& nums) {
        int size = (int)nums.size();
        
        return bSearch(nums, 0, size);
        
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {0, 2, 3, 4, 5};
    int result = s.findMagicIndex(nums);
    return 0;
}
