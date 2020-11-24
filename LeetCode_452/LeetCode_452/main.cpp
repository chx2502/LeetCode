//
//  main.cpp
//  LeetCode_452
//
//  Created by chx on 2020/11/23.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int size = (int)points.size();
        if (size == 0) return 0;
        auto cmp = [&](vector<int>& a, vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            else return a[1] < b[1];
        };
        sort(points.begin(), points.end(), cmp);
        int count = 1;
        vector<int> part = {-1, INT_MAX};
        for (int i = 0; i < size; i++) {
            vector<int> curr = points[i];
            if (curr[0] > part[1]) {
                count++;
                part[0] = curr[0];
                part[1] = curr[1];
            } else {
                part[0] = curr[0];
                part[1] = min(part[1], curr[1]);
            }
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> points = {
        {1, 2}, {3, 4}, {5, 6}, {7, 8}
    };
    int result = s.findMinArrowShots(points);
    return 0;
}
