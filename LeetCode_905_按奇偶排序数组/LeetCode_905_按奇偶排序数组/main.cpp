//
//  main.cpp
//  LeetCode_905_按奇偶排序数组
//
//  Created by chx on 2020/1/9.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
/*
 核心思路：
 双指针分别指向数组首尾，当左边为奇数且右边为偶数时则交换，
 否则移动相应指针到满足交换前提为止
 **/
class Solution {
public:
    bool isOdd(int x) {
        return (x & 1) == 1 ? true : false;
    }
    
    vector<int> sortArrayByParity(vector<int>& A) {
        int length = (int)A.size();
        if (length < 2) return A;
        int i, j;
        i = 0;
        j = length-1;
        while (i < j) {
            int left = A[i];
            int right = A[j];
            if (isOdd(left) && !isOdd(right)) {
                int temp = left;
                A[i] = right;
                A[j] = temp;
                i++;
                j--;
                continue;
            }
            while (isOdd(A[j]) && i < j) j--;
            while (!isOdd(A[i]) && i < j) i++;
        }
        return A;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> A = {0, 1, 2};
    Solution s;
    vector<int> result = s.sortArrayByParity(A);
    return 0;
}
