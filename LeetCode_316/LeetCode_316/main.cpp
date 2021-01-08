//
//  main.cpp
//  LeetCode_316
//
//  Created by chx on 2020/12/20.
//

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool> visited(26, false);
        vector<int> count(26, 0);
        for (auto c : s) count[c-'a']++;
        string result = "";
        for (auto c : s) {
            if (!visited[c-'a']) {
                while (!result.empty() && result.back() > c) {
                    if (count[result.back()-'a'] > 0) {
                        visited[result.back() - 'a'] = false;
                        result.pop_back();
                    } else break;
                }
                visited[c-'a'] = true;
                result.push_back(c);
            }
            count[c-'a']--;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    string s = "cbacdcbc";
    Solution solve;
    string res = solve.removeDuplicateLetters(s);
    return 0;
}
