//
//  main.cpp
//  LeetCode_560
//
//  Created by chx on 2020/5/15.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = (int)nums.size();
        if (size == 0) return 0;
        
        int result = 0;
        unordered_map<int, int> prefixSum_map;
        prefixSum_map[0] = 1;
        int curr= 0;
        for (int i = 0; i < size; ++i) {
            curr += nums[i];
            if (prefixSum_map.find(curr-k) != prefixSum_map.end())
                result += prefixSum_map[curr-k];
            if (prefixSum_map[curr]) prefixSum_map[curr] += 1;
            else prefixSum_map[curr] = 1;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1, 2, 4, -1, -3, 5, 0, 7};
    int result = s.subarraySum(nums, 6);
    return 0;
}
