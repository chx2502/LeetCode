//
//  main.cpp
//  LeetCode_1002_查找常用字符
//
//  Created by chx on 2020/2/20.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int length = (int)A.size();
        vector<string> result;
        if (!length) return result;
        vector<int> map(128, 0);
        for (auto &c : A[0]) map[c]++;
        for (int i = 1; i < length; i++) {
            vector<int> temp(128, 0);
            for (auto &c : A[i]) temp[c]++;
            for (char i = 'a'; i <= 'z'; i++) {
                if (map[i] > temp[i]) map[i] = temp[i];
            }
        }
        for (char i = 'a'; i <= 'z'; i++) {
            if (map[i]) {
                while (map[i]--) {
                    string s(1, i);
                    result.push_back(s);
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
