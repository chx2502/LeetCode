//
//  main.cpp
//  LeetCode_80
//
//  Created by chx on 2020/10/9.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
//    int removeDuplicates(vector<int>& nums) {
//        int size = (int)nums.size();
//        if (size == 0) return 0;
//        int curr = nums[0];
//        int count = 1;
//        for (int i = 1; i < size; i++) {
//            if (nums[i] == curr) count++;
//            else {
//                count = 1;
//                curr = nums[i];;
//            }
//            if (count > 2) {
//                for (int j = i+1; j < size; j++) nums[j-1] = nums[j];
//                i--;
//                size--;
//            }
//        }
//        return size;
//    }
    int removeDuplicates(vector<int>& nums) {
        int size = (int)nums.size();
        if (size == 0) return 0;
        int len = 0;
        for (auto &num : nums) {
            if (len < 2 || nums[len-2] != num)
                nums[len++] = num;
        }
        return len;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<int> nums = { 1, 1, 1, 2, 2, 3 };
    int res = s.removeDuplicates(nums);
    return 0;
}
