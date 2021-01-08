//
//  main.cpp
//  LeetCode_321
//
//  Created by chx on 2020/12/2.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        if (k == 0) return { };
        
        vector<int> result;
        int p, q;
        p = q = 0;

        return result;
    }
    
    vector<int> selectK(vector<int>& nums, int k) {
        int size = (int)nums.size();
        if (k > nums.size()) return {};
        if (k == nums.size()) return nums;
        
        vector<int> result;
        for (auto num : nums) {
            while (k && !result.empty() && result.back() < num) {
                result.pop_back();
                k--;
            }
            result.push_back(num);
        }
        return result = vector<int>(result.begin(), result.begin()+)
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums1 = {3, 4, 5, 6};
    vector<int> nums2 = {9, 1, 2, 5, 8, 3};
//    vector<int> result = s.maxNumber(nums1, nums2, 5);
    vector<int> res = s.selectK(nums2, 4);
    return 0;
}
