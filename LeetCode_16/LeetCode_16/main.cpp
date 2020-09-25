//
//  main.cpp
//  LeetCode_16
//
//  Created by chx on 2020/9/25.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> used;
    int nSumClosest(vector<int>& nums, int target, int n) {
        int min_distance = INT_MAX;
        if (n == 2) {
            int p,  q;
            p = 0;
            q = (int)nums.size()-1;
            while (p < q) {
                if (used[p]) {
                    p++;
                    continue;
                }
                if (used[q]) {
                    q--;
                    continue;
                }
                int front = nums[p];
                int back = nums[q];
                int distance = front - target + back;
                if (distance == 0) return target;
                if (distance > 0) q--;
                else p++;
                min_distance = abs(min_distance) > abs(distance) ? distance : min_distance;
            }
            return target + min_distance;
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (used[i]) continue;
                int curr = nums[i];
                used[i] = true;
                int sum = nums[i] + nSumClosest(nums, target-curr, n-1);
                used[i] = false;
                int distance = sum - target;
                if (distance == 0) return target;
                min_distance = abs(min_distance) > abs(distance) ? distance : min_distance;
            }
        }
        return target + min_distance;
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        used.assign(nums.size(), false);
        sort(nums.begin(), nums.end(), less<int>());
        return nSumClosest(nums, target, 4);
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1, 1, 1, -1, -1, 2, 3, 5};
    int result = s.threeSumClosest(nums, 5);
    return 0;
}
