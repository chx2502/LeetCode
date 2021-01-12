//
//  main.cpp
//  LeetCode_57
//
//  Created by chx on 2020/11/4.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int size = (int)intervals.size();
        if (size == 0) return {newInterval};
        
        vector<vector<int>> result;
        int i = 0;
        int l = newInterval[0];
        int r = newInterval[1];
        while (i < size && intervals[i][1] < l) {
            result.push_back(intervals[i]);
            i++;
        }
        while (i < size && intervals[i][0] <= r) {
            l = min(intervals[i][0], l);
            r = max(intervals[i][1], r);
            i++;
        }
        result.push_back({l, r});
        while (i < size) {
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> intervals = {
        {1,5},
    };
    vector<int> newInterval = {5, 7};
    vector<vector<int>> result = s.insert(intervals, newInterval);
    return 0;
}
