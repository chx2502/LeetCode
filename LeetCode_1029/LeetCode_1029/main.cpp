//
//  main.cpp
//  LeetCode_1029
//
//  Created by chx on 2020/7/2.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(
             costs.begin(),
             costs.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[0] - a[1] < b[0] - b[1]; }
        );
        int size = (int)costs.size();
        int N = size / 2;
        int result = 0;
        for (auto money : costs) {
            if (N-- > 0) result += money[0];
            else result += money[1];
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> costs = {
        {10 ,20},
        {30, 200},
        {400, 50},
        {30, 20},
    };
    int result = s.twoCitySchedCost(costs);
    return 0;
}
