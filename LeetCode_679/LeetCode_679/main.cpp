//
//  main.cpp
//  LeetCode_679
//
//  Created by chx on 2020/8/22.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

class Solution {
public:
    
    set<double> calc2(double a, double b) {
        set<double> result;
        if (a < b) swap(a, b);
        result.insert(a+b);
        result.insert(a-b);
        result.insert(a*b);
        if (b != 0) result.insert(a/b);
        return result;
    }
    
    set<double> calc3(double a, double b, double c) {
        set<double> result;
        set<double> ab = calc2(a, b);
        set<double> ac = calc2(a, c);
        set<double> bc = calc2(b, c);
        for (auto num : ab) {
            set<double> temp = calc2(num, c);
            for (auto n : temp) result.insert(n);
        }
        for (auto num : ac) {
            set<double> temp = calc2(num, b);
            for (auto n : temp) result.insert(n);
        }
        for (auto num : bc) {
            set<double> temp = calc2(num, a);
            for (auto n : temp) result.insert(n);
        }
        return result;
    }
    
    vector<vector<pair<int, int>>> choice2 = {
        {{0, 1}, {2, 3}},
        {{0, 2}, {1, 3}},
        {{0, 3}, {1, 2}},
    };
    
    vector<vector<vector<int>>> choice3 = {
        {{0}, {1, 2, 3}},
        {{1}, {0, 2, 3}},
        {{2}, {0, 1, 3}},
        {{3}, {0, 1, 2}},
    };
    
    bool judgePoint24(vector<int>& nums) {
        vector<double> dnums(nums.begin(), nums.end());
        for (auto &array : choice2) {
            set<double> set_1 = calc2(dnums[array[0].first], dnums[array[0].second]);
            set<double> set_2 = calc2(dnums[array[1].first], dnums[array[1].second]);
            for (auto num1 : set_1) {
                for (auto num2 : set_2) {
                    set<double> temp = calc2(num1, num2);
                    for (auto res : temp) {
                        if (abs(24.0 - res) < 0.1)
                            return true;
                    }
                }
            }
        }
        for (auto &array : choice3) {
            int a = dnums[array[0][0]];
            set<double> set_3 = calc3(dnums[array[1][0]], dnums[array[1][1]], dnums[array[1][2]]);
            for (auto num : set_3) {
                set<double> temp = calc2(a, num);
                for (auto res : temp) {
                    if (abs(24.0 - res) < 0.01)
                        return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1,3,4,6};
    bool result = s.judgePoint24(nums);
    return 0;
}
