//
//  main.cpp
//  LeetCode_327
//
//  Created by chx on 2020/11/7.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int size = (int)nums.size();
        if (size == 0) return 0;
        
        vector<long> dp(nums.begin(), nums.end());
        for (int i = 1; i < size; i++) dp[i] += dp[i-1];
        int result = 0;
        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                int sum = dp[j] - (dp[i] - nums[i]);
                if (sum >= lower && sum <= upper) result++;
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = { 2147483647,-2147483648,-1,0 };
    int lower = -1;
    int upper = 0;
    int result = s.countRangeSum(nums, lower, upper);
    return 0;
}
