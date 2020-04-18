//
//  main.cpp
//  LeetCode_228_汇总区间
//
//  Created by chx on 2020/4/18.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int size = (int)nums.size();
        if (size == 0) return result;
        
        int begin, end;
        begin = end = 0;
        while (end < size) {
            string section = "";
            while(end < size-1 && nums[end]+1 == nums[end+1]) end++;
            if (begin == end) section = to_string(nums[begin]);
            else section = to_string(nums[begin]) + "->" + to_string(nums[end]);
            begin = end+1;
            end = begin;
            result.push_back(section);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {-1};
    vector<string> result = s.summaryRanges(nums);
    return 0;
}
