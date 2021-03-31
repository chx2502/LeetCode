//
//  main.cpp
//  LeetCode_474
//
//  Created by chx on 2021/3/9.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int strCount(const string &s, char target) {
        int result = 0;
        for (auto &c : s) {
            if (c == target)
                result++;
        }
        return result;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        unordered_map<string, int> zeroCount;
        unordered_map<string, int> oneCount;
        
        for (const string &s : strs) {
            zeroCount[s] = strCount(s, '0');
            oneCount[s] = strCount(s, '1');
        }
        vector<vector<int>> dp(strs.size(), vector<int>(2, 0));
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
