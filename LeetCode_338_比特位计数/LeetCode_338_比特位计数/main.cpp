//
//  main.cpp
//  LeetCode_338_比特位计数
//
//  Created by chx on 2019/11/30.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     核心思路：
     动态规划，利用之前所求的结果计算当前 i 的结果。
     num == 0 时，返回 {0}
     将最近的一个 2 的整数次幂记为 j。
     当 i 是 2 的整数次幂时，i 的二进制数中 1 的数目为 1。
     当 i 不是 2 的整数次幂时，ret[i] = ret[j] + ret[i%j]
     例如：
     8 = 2^3, ret[8] = 1。
     13 % 8 = 5, 13 = 8 + 5, ret[13] = ret[8] + ret[5]
     5 % 4 = 1, 5 = 4 + 1, ret[5] = ret[4] + ret[1]
     */
//    vector<int> countBits(int num) {
//        vector<int> ret;
//        int i, j;
//        i = j = 0;
//        ret.push_back(0);
//        if (num > 0) ++j;
//        while (num > i++) {
//            int temp = i % j;
//            if (temp == 0) {
//                j = i;
//                ret.push_back(1);
//            } else {
//                ret.push_back(ret[j] + ret[temp]);
//            }
//        }
//        return ret;
//    }
    
    vector<int> countBits(int num) {
        vector<int> result(num+1, 0);
        if (num == 0) return result;
        int pre;
        result[1] = 1;
        if (num == 1) return result;
        result[2] = 1;
        pre = 2;
        for (int curr = 3; curr <= num; curr++) {
            int temp = curr % pre;
            if (temp != 0) result[curr] = result[pre] + result[temp];
            else {
                pre = curr;
                result[curr] = 1;
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
//    int num = 0x7FFFFFFF;
//    vector<int> result = s.countBits(num);
    cout << 2%0 << endl;
    return 0;
}
