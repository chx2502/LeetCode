//
//  main.cpp
//  LeetCode_91
//
//  Created by chx on 2021/1/4.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool mapping(string s) {
        int num = stoi(s);
        if (num >= 1 && num <= 26) return true;
        else return false;
    }
    int numDecodings(string s) {
        int length = (int)s.length();
        for (int i = 1; i < length; i++) {
            string left = s.substr(0, i);
            string right = s.substr(i, length-i);
            if (mapping(s)) {
                return
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
