//
//  main.cpp
//  LeetCode_周赛#182_1
//
//  Created by chx on 2020/3/29.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    const int MAX = 501;
    int findLucky(vector<int>& arr) {
        vector<int> map(MAX, 0);
        int max = 0;
        int result = -1;
        for (auto &num : arr) {
            map[num] += 1;
            max = max < num ? num : max;
        }
        for(int i = 1; i <= max; ++i) {
            if (map[i] == i) {
                result = result < i ? i : result;
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
