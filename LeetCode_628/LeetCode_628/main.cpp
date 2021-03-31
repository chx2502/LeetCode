//
//  main.cpp
//  LeetCode_628
//
//  Created by chx on 2021/1/20.
//

#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1, max2, max3;
        int min1, min2;
        max1 = max2 = max3 = INT_MIN;
        min1 = min2 = INT_MAX;
        for (auto &num : nums) {
            if (max1 < num) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if(max2 < num) {
                max3 = max2;
                max2 = num;
            } else if (max3 < num) {
                max3 = num;
            }
            
            if (min1 > num) {
                min2 = min1;
                min1 = num;
            } else if(min2 > num) {
                min2 = num;
            }
        }
        return max(max1 * max2 * max3, max1 * min1 * min2);
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 2, 3, 4, -1, -100, -98};
    Solution s;
    int result = s.maximumProduct(nums);
    return 0;
}
