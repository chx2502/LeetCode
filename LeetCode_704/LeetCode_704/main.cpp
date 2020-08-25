//
//  main.cpp
//  LeetCode_704
//
//  Created by chx on 2020/8/23.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bSearch(vector<int>& nums, int begin, int end, int target) {
        if (begin > end) return -1;
        int mid = begin + (end-begin)/2;
        if (nums[mid] == target) return mid;
        if (nums[mid] > target) return bSearch(nums, begin, mid-1, target);
        else return bSearch(nums, mid+1, end, target);
    }
    
    int search(vector<int>& nums, int target) {
        return bSearch(nums, 0, nums.size()-1, target);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
