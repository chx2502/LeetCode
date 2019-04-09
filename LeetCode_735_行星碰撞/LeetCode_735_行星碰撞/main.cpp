//
//  main.cpp
//  LeetCode_735_行星碰撞
//
//  Created by 成鑫 on 2019/1/11.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX_SIZE = 1001;
const int MAX_LEN = 10000;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        stack<int> myStack;
        for (auto i = asteroids.cbegin(); i < asteroids.cend(); ++i) {
            int ast = *i;
            if (myStack.empty() || ast > 0) {
                myStack.push(ast);
                continue;
            }
            while (!myStack.empty()) {
                int collision = myStack.top();
                if (collision < 0) {
                    myStack.push(ast);
                    break;
                }
                if (collision > abs(ast)) break;
                if (collision == abs(ast)) {
                    myStack.pop();
                    break;
                }
                if (collision < abs(ast)) {
                    myStack.pop();
                    if (myStack.empty()) {
                        myStack.push(ast);
                        break;
                    }
                }
            }
        }
        stack<int> tmpStack;
        while (!myStack.empty()) {
            int tmp = myStack.top();
            tmpStack.push(tmp);
            myStack.pop();
        }
        while (!tmpStack.empty()) {
            int tmp = tmpStack.top();
            res.push_back(tmp);
            tmpStack.pop();
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> asteroids = {10, 2, -5};
    Solution s;
    vector<int> result = s.asteroidCollision(asteroids);
    return 0;
}
