//
//  main.cpp
//  LeetCode_1047_删除字符串中的所有相邻重复项
//
//  Created by chx on 2020/2/15.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>
#include <deque>

using namespace std;

class Solution {
public:
    /*
     解法 1:
     每次去除当前 S 中的所有字母对，生成 result 作为下一轮的输入。
     直到字符串为空或不再有字母对。
     **/
//    string removeDuplicates(string S) {
//        int length = (int)S.length();
//        if (length == 0) return S;
//        string result = "";
//        for (int i = 0; i < length; i++) {
//            if (S[i] != S[i+1]) result.push_back(S[i]);
//            else i++;
//        }
//        if (result.length() == length) return result;
//        else return removeDuplicates(result);
//    }
    /*
     解法 2:
     双端队列模拟栈，遇到与栈顶相同的元素则弹出栈顶元素，反之将当前元素入栈。
     最后的正向队列就是结果。
     **/
    string removeDuplicates(string S) {
        int length = (int)S.length();
        if (length == 0) return S;
        deque<char> dq;
        for (auto &c : S) {
            if (dq.empty() || c != dq.back()) dq.push_back(c);
            else dq.pop_back();
        }
        string result = "";
        while (!dq.empty()) {
            result.push_back(dq.front());
            dq.pop_front();
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
