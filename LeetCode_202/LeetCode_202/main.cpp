//
//  main.cpp
//  LeetCode_202
//
//  Created by chx on 2020/4/30.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<int> visited;
    bool isHappy(int n) {
        if (n == 1) return true;
        if (visited.find(n) != visited.end()) return false;
        visited.insert(n);
        int sum = 0;
        while (n) {
            int temp = n%10;
            sum += temp*temp;
            n /= 10;
        }
        return isHappy(sum);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int n = 12;
    bool result = s.isHappy(n);
    return 0;
}
