//
//  main.cpp
//  LeetCode_266
//
//  Created by chx on 2020/10/22.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> charMap;
        for (auto c : s) {
            charMap[c]++;
        }
        int count = 0;
        for (auto item : charMap) {
            if (item.second&1) count++;
            if (count > 1) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
