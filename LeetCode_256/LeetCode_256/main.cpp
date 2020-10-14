//
//  main.cpp
//  LeetCode_256
//
//  Created by chx on 2020/10/10.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = (int)costs.size();
        if (n == 0) return 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                vector<int> temp;
                for (int k = 0; k < 3; k++) {
                    if (k == j) continue;
                    temp.push_back(k);
                }
                costs[i][j] += min(costs[i-1][temp[0]], costs[i-1][temp[1]]);
            }
        }
        return min({ costs[n-1][0], costs[n-1][1], costs[n-1][2] });
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> costs = {
        {17, 2, 17},
        {16, 16, 5},
        {14, 3, 19}
    };
    int res = s.minCost(costs);
    return 0;
}
