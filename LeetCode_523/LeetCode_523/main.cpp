//
//  main.cpp
//  LeetCode_523
//
//  Created by 成鑫 on 2019/1/6.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, int> memory;
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int size = (int)nums.size();
        vector<int> preSum(size+1, 0);
        memory[0] = 0;
        for (int i = 1; i <= size; i++) {
            preSum[i] = preSum[i-1] + nums[i-1];
            int mod = preSum[i] % k;
            auto it = memory.find(mod);
            if (it != memory.end()) {
                // printf("i = %d, mod = %d, preIndex = %d", i, mod, memory[mod]);
                if (i-(it->second) >= 2) return true; 
            } else memory[mod] = i;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {23, 2, 4, 6, 6};
    int k = 7;
    bool result = s.checkSubarraySum(nums, k);
    return 0;
}
