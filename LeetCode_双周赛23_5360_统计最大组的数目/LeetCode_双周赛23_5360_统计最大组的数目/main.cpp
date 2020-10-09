//
//  main.cpp
//  LeetCode_双周赛23_5360_统计最大组的数目
//
//  Created by chx on 2020/4/4.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        map<int, int> M;
        int max, count;
        max = count = 0;
        for (int i = 1; i <= n; ++i) {
            int sum = 0;
            int temp = i;
            while (temp) {
                sum += temp%10;
                temp /= 10;
            }
            M[sum] += 1;
            if (M[sum] > max) {
                max = M[sum];
                count = 1;
            } else if (M[sum] == max) count += 1;
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int n = 13;
    int res = s.countLargestGroup(n);
    return 0;
}
