//
//  main.cpp
//  LeetCode_260
//
//  Created by chx on 2020/11/24.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int bitsmask = 0;
        for (auto num : nums) {
            bitsmask ^= num;
        }
        int diff = bitsmask & (-bitsmask);
        int x = 0;
        for (auto num : nums) {
            if (diff&num) x ^= num;
        }
        int y = bitsmask ^ x;
        return {x, y};
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = { 2, 3, 4, 5, 6, 7, 2, 3, 4, 5, 6, 8 };
    vector<int> result = s.singleNumber(nums);
    return 0;
}
