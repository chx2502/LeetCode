//
//  main.cpp
//  LeetCode_344_反转字符串
//
//  Created by chx on 2020/1/8.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
/*
 水题
 **/
class Solution {
public:
    void reverseString(vector<char>& s) {
        int length = (int)s.size();
        int i, j;
        i = 0;
        j = length-1;
        while(i < j) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
