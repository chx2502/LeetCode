//
//  main.cpp
//  LeetCode_双周赛25
//
//  Created by chx on 2020/5/2.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getDigit(int num) {
        vector<int> result;
        while (num) {
            result.insert(result.begin(), num%10);
            num /= 10;
        }
        return result;
    }
    int getNum(vector<int>& array) {
        int result = 0;
        for (auto &i : array) {
            result = result * 10 + i;
        }
        return result;
    }
    int maxDiff(int num) {
        int a, b;
        vector<int> array1 = getDigit(num);
        vector<int> array2(array1.begin(), array1.end());
        int size = (int)array1.size();
        int idx = 0;
        int all = array1[0];
        bool same = true;
        for (auto &i : array1) {
            if (i != all) {
                same = false;
                break;
            }
        }
        if (same) {
            array1 = vector<int>(size, 9);
            array2 = vector<int>(size, 1);
            return getNum(array1) - getNum(array2);
        }
        int target = -1;
        while (idx < size) {
            if (array1[idx] != 9) {
                target = array1[idx];
                break;
            }
            idx += 1;
        }
        if (idx == size) array1 = vector<int>(8, size);
        else {
            for (auto &i : array1) {
                if (i == target) i = 9;
            }
        }
        a = getNum(array1);
        idx = 0;
        target = -1;
        if (array2[idx++] != 1) {
            target = array2[0];
        } else {
            if (num%10) {
                while (idx < size) {
                    if (array2[idx] != 0) {
                        target = array2[idx];
                        break;
                    }
                    idx++;
                }
            } else target = 0;
        }
        int change = 0;
        if (target != 0) {
            for (int i = 0; i < size; ++i) {
                if (array2[i] == target) {
                    if (i == 0) change = 1;
                    array2[i] = change;
                }
            }
        }
        b = getNum(array2);
        return a-b;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int num = 9288;
    int result = s.maxDiff(num);
    return 0;
}
