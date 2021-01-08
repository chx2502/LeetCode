//
//  main.cpp
//  LeetCode_387
//
//  Created by chx on 2020/12/23.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> memory(26);
        for (auto c : s) memory[c-'a']++;
        int result = -1;
        for (int i = 0; i < s.length(); i++) {
            if (memory[s[i]-'a'] == 1) {
                result = i;
                break;
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solve;
    string s = "loveleetcode";
    int res = solve.firstUniqChar(s);
    return 0;
}
