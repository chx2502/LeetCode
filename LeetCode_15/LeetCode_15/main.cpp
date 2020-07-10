//
//  main.cpp
//  LeetCode_15
//
//  Created by chx on 2020/7/10.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int start, int size, int target) {
        int low, high;
        low = start;
        high = size-1;

        vector<vector<int>> result;
        while (low < high) {
            while (low < high && nums[low] + nums[high] < target) low++;
            while (low < high && nums[low] + nums[high] > target) high--;
            if (low < high && nums[low] + nums[high] == target) {
                result.push_back({nums[low], nums[high]});
                low++;
                high--;
            }
            while (low < high && nums[low-1] == nums[low]) low++;
            while (low < high && nums[high+1] == nums[high]) high--;
        }
        return result;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int size = (int)nums.size();
        if (size < 3) return result;
        sort(nums.begin(), nums.end(), less<int>());

        for (int i = 0; i < size-1; ++i) {
            vector<vector<int>> temp = twoSum(nums, i+1, size, -nums[i]);
            if (temp.size()) {
                for (auto &array : temp) {
                    array.insert(array.begin(), nums[i]);
                    result.push_back(array);
                }
            }
            while (i < size-1 && nums[i+1] == nums[i]) ++i;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {3, -2, 1, 0};
    vector<vector<int>> result = s.threeSum(nums);
    return 0;
}
