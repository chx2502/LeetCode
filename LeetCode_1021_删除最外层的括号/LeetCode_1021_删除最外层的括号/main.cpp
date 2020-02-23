//
//  main.cpp
//  LeetCode_1021_删除最外层的括号
//
//  Created by chx on 2020/2/23.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    /*
     核心思路：
     用队列保存当前已读字符，用 count 来计算当前括号对数，
     当 count = 0 时说明已经读完一个原语，弹出队列中除第一个'('外的所有字符
     直到读完整个字符串
     **/
    string removeOuterParentheses(string S) {
        queue<char> Q;
        string result = "";
        int count = 0;
        for (char c : S) {
            if (c == '(') count++;
            else count--;
            if (count == 0) {
                Q.pop();
                while (!Q.empty()) {
                    char temp = Q.front();
                    Q.pop();
                    result.push_back(temp);
                }
            } else Q.push(c);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
