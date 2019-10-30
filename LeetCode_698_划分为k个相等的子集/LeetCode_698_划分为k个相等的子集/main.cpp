//
//  main.cpp
//  LeetCode_698_划分为k个相等的子集
//
//  Created by chx on 2019/10/14.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isLegal(vector<int>& nums,
                 vector<bool>& used,
                 int average,
                 int target_val,
                 int k,
                 int pos)
    {
        if (k == 0) return true;
        
        if (target_val == 0)
            return isLegal(nums, used, average, average, k-1, 0);
        
        for (int i = pos; i < nums.size(); i++) {
            if (used[i]) continue;
            
            used[i] = true;
            
            if (target_val - nums[i] >= 0 && isLegal(nums, used, average,
                                                     target_val-nums[i],
                                                     k, pos+1))
            {
                return true;
            }
            used[i] = false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int length = (int)nums.size();
        if (length == 0) return false;

        int sum = 0;
        int max_val = 0;
        for (auto i = nums.begin(); i != nums.end(); i++) {
            sum += *i;
            if (*i > max_val) max_val = *i;
        }
        if (sum % k > 0) return false;
        
        int average = sum / k;
        if (average < max_val) return false;
        vector<bool> used(length, false);
        
        return isLegal(nums, used, average, average, k, 0);
        
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {10,10,10,7,7,7,7,7,7,6,6,6};
//    auto i = nums.begin();
//    nums.erase(i);
//    cout << nums.size() << endl;
//    for (auto &i : nums)
//        cout << i << " ";
//    cout << endl;
    Solution s;
    int k = 3;
    bool result = s.canPartitionKSubsets(nums, k);
    cout << result << endl;
    return 0;
}
