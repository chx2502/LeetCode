//
//  main.cpp
//  LeetCode_368
//
//  Created by chx on 2021/4/23.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        unsigned long size = nums.size();
        if (size < 2) return nums;
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> dp(size);
        int index = 0;
        unsigned long maxSize = 0;
        dp[0] = {nums[0]};
        for (int i = 1; i < size; i++) {
            int curr = nums[i];
            dp[i].push_back(curr);
            for (int j = i-1; j >= 0; j--) {
                if (curr % dp[j].back() == 0 && dp[j].size()+1 > dp[i].size()) {
                    dp[i] = dp[j];
                    dp[i].push_back(curr);
                }
            }
            if (dp[i].size() > maxSize) {
                maxSize = dp[i].size();
                index = i;
            }
        }
        return dp[index];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {2, 3, 4, 9, 8};
    vector<int> result = s.largestDivisibleSubset(nums);
    return 0;
}
