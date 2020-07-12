//
//  main.cpp
//  LeetCode_17
//
//  Created by chx on 2020/7/10.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, string> digit_map = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        int length = (int)digits.length();
        if (length == 0) return result;
        string curr = "";
        dfs(0, curr, digits, result);
        
        return result;
    }
    
    void dfs(int pos, string curr, string &s, vector<string>& result) {
        if (pos == s.length()) {
            result.push_back(curr);
            return;
        }
        char digit = s[pos];
        string charstr = digit_map[digit];
        for (auto c : charstr) {
            curr.push_back(c);
            dfs(pos+1, curr, s, result);
            curr.pop_back();
        }
    }
    
};

int main(int argc, const char * argv[]) {
    Solution s;
    string digits = "23";
    vector<string> result = s.letterCombinations(digits);
    return 0;
}
