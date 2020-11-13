//
//  main.cpp
//  Leetcode_389
//
//  Created by chx on 2020/10/23.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> memory(128, 0);
        for (auto c : s) memory[c]++;
        for (auto c : t) {
            if (memory[c] == 0) return c;
            memory[c]--;
        }
        return '0';
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
