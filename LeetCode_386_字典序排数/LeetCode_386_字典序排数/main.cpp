//
//  main.cpp
//  LeetCode_386_字典序排数
//
//  Created by chx on 2020/1/12.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    /*
     核心思路：
     深度优先遍历 10 叉树
     **/
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        stack<int> stk;
        if (n < 10) {
            for (int i = n; i > 0; --i) {
                stk.push(i);
            }
        } else {
            for (int i = 9; i > 0; --i) {
                stk.push(i);
            }
        }
        int current, distance;
        while (!stk.empty()) {
            current = stk.top();
            stk.pop();
            res.push_back(current);
            if (current * 10 > n) continue;
            else {
                distance = n - current * 10;
                if (distance > 9) distance = 9;
            }
            for (int i = distance; i >= 0; --i) {
                int temp = current * 10 + i;
                if (temp <= n)
                    stk.push(temp);
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int n = 13;
    vector<int> result = s.lexicalOrder(n);
    for (auto &num : result) {
        cout << num << " ";
    }
    return 0;
}
