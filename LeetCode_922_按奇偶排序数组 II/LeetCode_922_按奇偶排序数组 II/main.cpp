//
//  main.cpp
//  LeetCode_922_按奇偶排序数组 II
//
//  Created by chx on 2020/1/14.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     核心思路：
     令 i, j 分别为偶数下标和奇数下标，
     若 A[i] 为奇数 A[j] 为偶数，则交换两者后移动 i 和 j，
     否则移动 i 或 j 直到满足交换条件。
     **/
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    vector<int> sortArrayByParityII(vector<int>& A) {
        int length = (int)A.size();
        int i, j;
        i = 0;
        j = 1;
        while (i < length && j < length) {
            if (A[i] % 2 == 1 && A[j] % 2 == 0) {
                swap(A[i], A[j]);
                i += 2;
                j += 2;
            } else {
                if (A[i] % 2 == 1) j += 2;
                else i += 2;
            }
        }
        return A;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
