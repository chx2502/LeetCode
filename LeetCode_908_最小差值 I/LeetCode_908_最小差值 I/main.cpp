//
//  main.cpp
//  LeetCode_908_最小差值 I
//
//  Created by chx on 2020/1/11.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     核心思路：
     对于 A 中元素 x，可取值范围为[x-K, x+K]，
     于是 A 中最小的差值为 [min, min+K] 中元素与 [max-K, max] 中元素的最小差值
     **/
    int smallestRangeI(vector<int>& A, int K) {
        int length = (int)A.size();
        if (length == 1) return 0;
        int min, max;
        min = INT_MAX;
        max = INT_MIN;
        for (auto &num : A) {
            if (min > num) min = num;
            if (max < num) max = num;
        }
        int distance = max - min - 2*K;
        if (distance > 0) return distance;
        else return 0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
