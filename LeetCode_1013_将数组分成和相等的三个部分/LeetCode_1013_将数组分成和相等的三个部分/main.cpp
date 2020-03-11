//
//  main.cpp
//  LeetCode_1013_将数组分成和相等的三个部分
//
//  Created by chx on 2020/3/11.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    /*
     原地将 A[i] 依次变为 [0, i] 区间和
     A[size-1] 即为全部元素和 sum
     sum % 3 != 0 则无法三等分，返回 false
     否则从 i = size-2 开始找 2 * sum/3 和 sum/3，
     count = 1，每找到一次，count += 1, count == 3 时返回 true
     **/
    bool canThreePartsEqualSum(vector<int>& A) {
        int size = (int)A.size();
        bool result = false;
        for (int i = 1; i < size; ++i) {
            A[i] += A[i-1];
        }
        int sum = A[size-1];
        if (sum % 3 != 0) return false;
        int p_sum = sum/3;
        int target = sum - p_sum;
        int count = 1;
        for (int i = size-2; i >=0; i--) {
            if (A[i] == target) {
                target -= p_sum;
                count++;
                if (count == 3) {
                    result = true;
                    break;
                }
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
