//
//  main.cpp
//  LeetCode_350
//
//  Created by chx on 2020/7/13.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int size1 = (int)nums1.size();
        int size2 = (int)nums2.size();
        if (size1 == 0 || size2 == 0) return result;
        
        if (size1 > size2) {
            swap(nums1, nums2);
            swap(size1, size2);
        }
        
        unordered_map<int, int> num_map;
        for (auto num : nums1) {
            if (num_map.find(num) == num_map.end()) num_map[num] = 1;
            else num_map[num] += 1;
        }
        
        for (auto num : nums2) {
            if (num_map.find(num) == num_map.end() || num_map[num] == 0)
                continue;
            else {
                num_map[num] -= 1;
                result.push_back(num);
            }
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    vector<int> result = s.intersect(nums1, nums2);
    return 0;
}
