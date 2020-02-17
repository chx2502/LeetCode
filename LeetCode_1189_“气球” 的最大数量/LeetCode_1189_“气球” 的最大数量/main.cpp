//
//  main.cpp
//  LeetCode_1189_“气球” 的最大数量
//
//  Created by chx on 2020/2/17.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> map(128, 0);
        for (auto c : text) {
            map[c]++;
        }
        int a, b, l, o, n;
        vector<int> array;
        array.push_back(map['a']);
        array.push_back(map['b']);
        array.push_back(map['l'] / 2);
        array.push_back(map['o'] / 2);
        array.push_back(map['n']);
        int min = INT_MAX;
        for (auto count : array) {
            if (count < min) min = count;
        }
        return min;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
