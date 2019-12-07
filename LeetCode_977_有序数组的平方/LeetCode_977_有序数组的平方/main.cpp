//
//  main.cpp
//  LeetCode_977_有序数组的平方
//
//  Created by chx on 2019/12/4.
//  Copyright © 2019 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     解法 1：
     先平方再排序
     **/
//    vector<int> sortedSquares(vector<int>& A) {
//        for (auto &num : A) {
//            num *= num;
//        }
//        sort(A.begin(), A.end(), less<int>());
//        return A;
//    }
    /*
     解法 2：
     双指针，p 遍历按升序正数，q 按降序遍历负数，二者的值取平方后合并输出
     **/
    vector<int> sortedSquares(vector<int>& A) {
        vector<int>::iterator p, q;
        vector<int> ret;
        p = A.begin();
        q = A.end()-1;
        if (*q < 0) {
            q = A.end()-1;
            while (q >= A.begin()) {
                ret.push_back((*q)*(*q));
                q--;
            }
            return ret;
        }
        while (*p < 0) p++;
        if (p == A.begin()) {
            for (auto &num : A)
                num *= num;
            return A;
        }
        else {
            q = p-1;
            while (q >= A.begin() && p < A.end()) {
                int a = (*p) * (*p);
                int b = (*q) * (*q);
                if (a < b) {
                    ret.push_back(a);
                    p++;
                }
                else {
                    ret.push_back(b);
                    q--;
                }
            }
            while (p < A.end()) {
                ret.push_back((*p)*(*p));
                p++;
            }
            while (q >= A.begin()) {
                ret.push_back((*q)*(*q));
                q--;
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> A = {-1, 2, 2};
    Solution s;
    vector<int> result = s.sortedSquares(A);
    return 0;
}
