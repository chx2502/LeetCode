//
//  main.cpp
//  LeetCode_746
//
//  Created by chx on 2020/9/30.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = (int)cost.size();
        int res1, res2;
        res1 = res2 = 0;
        for (int i = size-1; i >= 0; i--) {
            int temp = cost[i] + min(res1, res2);
            res2 = res1;
            res1 = temp;
        }
        return min(res1, res2);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> cost = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
    int result = s.minCostClimbingStairs(cost);
    return 0;
}
