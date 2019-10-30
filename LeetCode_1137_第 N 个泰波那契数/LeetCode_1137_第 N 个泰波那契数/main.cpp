//
//  main.cpp
//  LeetCode_1137_第 N 个泰波那契数
//
//  Created by chx on 2019/10/24.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        vector<int> array = {0, 1, 1};
        if (n < 3) return array[n];
        int i, j, k, p;
        i = 0;
        j = 1;
        k = 2;
        p = 3;
        while(p++ <= n) array.push_back(array[i++] + array[j++] + array[k++]);
        return array[n];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int result = s.tribonacci(25);
    cout << result << endl;
    return 0;
}
