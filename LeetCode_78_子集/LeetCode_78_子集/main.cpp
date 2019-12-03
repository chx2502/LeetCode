//
//  main.cpp
//  LeetCode_78_子集
//
//  Created by chx on 2019/11/10.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        ret.push_back(vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            int len = (int)ret.size();
            for (int j = 0; j < len; j++) {
                ret.push_back(ret[j]);
                ret[j].push_back(nums[i]);
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> result = s.subsets(nums);
    return 0;
}
