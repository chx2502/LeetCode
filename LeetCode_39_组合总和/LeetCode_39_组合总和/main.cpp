//
//  main.cpp
//  LeetCode_39_组合总和
//
//  Created by chx on 2020/3/25.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    
    void backTracking(vector<int>& curr, int begin, vector<int>& cantidate, int target, int size, vector<vector<int>>& result) {
        if (target < 0) return;
        if (target == 0) {
            result.push_back(vector<int>(curr));
            return;
        }
        for (int i = begin; i < size; ++i) {
            int temp = cantidate[i];
            curr.push_back(cantidate[i]);
            backTracking(curr, i, cantidate, target-temp, size, result);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int size = (int)candidates.size();
        vector<vector<int>> result;
        if (size == 0) return result;
        sort(candidates.begin(), candidates.end(), less<int>());
        vector<int> curr;
        backTracking(curr, 0, candidates, target, size, result);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = s.combinationSum(candidates, target);
    return 0;
}
