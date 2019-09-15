//
//  main.cpp
//  LeetCode_264_丑数 II
//
//  Created by 成鑫 on 2019/7/12.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int min(int a, int b) {
        return a < b ? a : b;
    }
    /* 三指针分别指向 2, 3, 5 需要相乘的位置，每轮相乘后取三者最小值，对应的指针自加 1，
     多个指针同时得到最小值则都自加1，目的是去重 */
    int nthUglyNumber(int n) {
        vector<int> array = {1};
        int i, j, k;
        i = j = k = 0;
        while (array.size() < n) {
            int temp = min(min(array[i] * 2, array[j] * 3), array[k] * 5);
            array.push_back(temp);
            if (temp == array[i] * 2) i++;
            if (temp == array[j] * 3) j++;
            if (temp == array[k] * 5) k++;
        }
        return array[n-1];
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
