//
//  main.cpp
//  LeetCode_41
//
//  Created by chx on 2021/4/28.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unsigned long size = nums.size();
        
        bool haveOne = false;
        for (int i = 0; i < size; i++) {
            if (nums[i] == 1) {
                haveOne = true;
                break;
            }
        }
        if (!haveOne) return 1;
        
        for (int i = 0; i < size; i++) {
            int curr = nums[i];
            if (curr < 1 || curr > size) {
                nums[i] = 1;
            }
        }
        
        for (int i = 0; i < size; i++) {
            int index = abs(nums[i])-1;
            if (nums[index] > 0) nums[index] *= -1;
        }
        
        for (int i = 1; i < size; i++) {
            if (nums[i] > 0) return i+1;
        }
        return (int)size+1;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1,2,6,3,5,4};
    int result = s.firstMissingPositive(nums);
    return 0;
}
