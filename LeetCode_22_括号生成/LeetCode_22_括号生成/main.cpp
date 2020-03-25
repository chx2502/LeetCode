//
//  main.cpp
//  LeetCode_22_括号生成
//
//  Created by chx on 2020/3/25.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
//    bool isLegal(string s) {
//        int count = 0;
//        for (auto &c : s) {
//            if (c == '(') ++count;
//            else -- count;
//            if (count < 0) return false;
//        }
//        return true;
//    }
    // 此算法超时
//    void backtracking(string curr, int first, set<string>& output, int size) {
//        if (first == size) {
//            if (isLegal(curr))
//                output.insert(curr);
//            return;
//        }
//
//        for (int i = first; i < size; ++i) {
//            swap(curr[first], curr[i]);
//            backtracking(curr, first+1, output, size);
//            swap(curr[first], curr[i]);
//        }
//    }
    
    void backTracking(string curr, int left, int right, vector<string>& result) {
        if (right < left) return;
        if (left == 0 && right == 0) {
            result.push_back(curr);
            return;
        }
        if (left > 0) backTracking(curr + '(', left-1, right, result);
        if (right > 0) backTracking(curr + ')', left, right-1, result);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0) return result;
        backTracking("", n, n, result);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    int n = 5;
    Solution s;
    vector<string> result = s.generateParenthesis(n);
    return 0;
}
