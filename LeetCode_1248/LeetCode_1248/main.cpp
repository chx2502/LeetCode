//
//  main.cpp
//  LeetCode_1248
//
//  Created by chx on 2020/4/21.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /* 参考官方题解："https://leetcode-cn.com/problems/count-number-of-nice-subarrays/solution/tong-ji-you-mei-zi-shu-zu-by-leetcode-solution/
     **/
    int numberOfSubarrays(vector<int>& nums, int k) {
        int size = (int)nums.size();
        if (size < k) return 0;
        int count = 0;
        int result = 0;
        vector<int> choice(size+1, 0);
        choice[0] = 1;
        for (int i = 0; i < size ; ++i) {
            if (nums[i] & 1) ++count;
            result += count >= k ? choice[count-k] : 0;
            choice[count] += 1;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1, 1, 2, 1, 1};
    int result = s.numberOfSubarrays(nums, 2);
    return 0;
}
