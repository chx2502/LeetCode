//
//  main.cpp
//  LeetCode_1103_分糖果 II
//
//  Created by chx on 2020/3/5.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     常规解法:
     依次分配糖果直到糖果分完。
     **/
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people, 0);
        int round = 0;
        int cost = 0;
        while (candies) {
            for (int i = 0; i < num_people; ++i) {
                cost = round*num_people + i + 1;
                if (candies < cost) {
                    result[i] += candies;
                    candies = 0;
                    break;
                } else {
                    result[i] += cost;
                    candies -= cost;
                }
            }
            round++;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> result = s.distributeCandies(60, 4);
    return 0;
}
