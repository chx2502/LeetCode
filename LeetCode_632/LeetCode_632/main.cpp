//
//  main.cpp
//  LeetCode_632
//
//  Created by chx on 2020/8/1.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    unordered_map<int, vector<int>> num_map;
    vector<int> covered;
    vector<int> bound;
    
    int checkRight(int num) {
        if (num_map[num].empty()) return 0;
        int result = 0;
        for (auto group : num_map[num]) {
            covered[group] += 1;
            if(covered[group == 1])
                result++;
        }
        return result;
    }
    
    int checkLeft(int num) {
        if (num_map[num].empty()) return 0;
        int result = 0;
        for (auto group : num_map[num]) {
            covered[group]--;
            if (covered[group] == 0)
                result++;
        }
        return result;
    }
    
    vector<int> searchSection(int begin, int end, int& next, int remain) {
        if (begin > end) return {};
        vector<int> result;
        int l, r;
        l = begin;
        r = l+1;
        while(r <= end) {
            int new_cover = checkRight(r);
            if (new_cover > 0) {
                dp[l][r] = dp[l][r-1] + new_cover;
                if (dp[l][r] == remain) {
                    while(checkLeft(l) == 0) l++;
                    if (result.empty()) {
                        result.push_back(l);
                        result.push_back(r);
                    } else {
                        if (result[1] - result[0] > r-l) result = {l, r};
                        else if (result[1] - result[0] == r-l) {
                            if (result[0] > l) result = {l, r};
                        }
                    }
                }
            } else dp[l][r] = dp[l][r-1];
            r++;
        }
        if (!result.empty())
            return result;
        next += 1;
        return searchSection(end, bound[next], next, remain-dp[l][r]);
    }
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int size = (int)nums.size();
        int begin, end;
        begin = INT_MIN;
        end = INT_MAX;
        for (int i = 0; i < size; i++) {
            int left = nums[i].front();
            int right = nums[i].back();
            bound.push_back(right);
            begin = begin < left ? left : begin;
            end = end < right ? end : right;
            for (auto &num : nums[i]) {
                num_map[num].push_back(i);
            }
        }
        dp.assign(end+1, vector<int>(end+1, 0));
        covered.assign(size, 0);
        sort(bound.begin(), bound.end(), less<int>());
        bound.push_back(-1);
        dp[0][0] = checkRight(begin);
        vector<vector<int>> answers;
        int next = 1;
        return searchSection(begin, bound[0], next, size);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30},
    };
    vector<int> result = s.smallestRange(nums);
    return 0;
}
