//
//  main.cpp
//  LeetCode_1207_独一无二的出现次数
//
//  Created by chx on 2020/1/10.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> map = vector<int>(2001, 0);
        vector<int> count = vector<int>(arr.size(), 0);
        for (auto &num : arr) {
            map[num+1000] += 1;
        }
        for (auto &num : map) {
            if (num > 0) {
                count[num] += 1;
                if (count[num] == 2) return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> arr = {1, 2, 2, 1, 1, 3};
    Solution s;
    bool result = s.uniqueOccurrences(arr);
    
    return 0;
}
