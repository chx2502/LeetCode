//
//  main.cpp
//  LeetCode_18
//
//  Created by chx on 2020/7/7.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    vector<vector<int>> nSum(vector<int> &nums, int target, int n, int start) {
        vector<vector<int>> result;
        int size = (int)nums.size()-start;
        if (size < n || n == 0) return result;

        if (n == 2) {
            int low, high;
            low = start;
            high = start + size - 1;
            while (low < high) {
                while (low < high && nums[low] + nums[high] < target) low++;
                while (low < high && nums[low] + nums[high] > target) high--;
                while (low < high && nums[low] + nums[high] == target) {
                    vector<int> temp = {nums[low], nums[high]};
                    result.push_back(temp);
                    ++low;
                    --high;
                    while (low < high && nums[low] == nums[low-1]) ++low;
                    while (high > low && nums[high] == nums[high+1]) --high;
                    if (low >= high) break;
                }
            }
        } else {
            for (int i = start; i < size+start; ++i) {
                vector<vector<int>> counterPart = nSum(nums, target-nums[i], n-1, i+1);
                if (counterPart.size()) {
                    for (auto &array : counterPart) {
                        array.insert(array.begin(), nums[i]);
                        result.push_back(array);
                    }
                }
                while (i < start+size-1 && nums[i] == nums[i+1]) i++;
            }
        }
        return result;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end(), less<int>());
        return nSum(nums, target, 4, 0);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = s.fourSum(nums, target);
    return 0;
}
