//
//  main.cpp
//  LeetCode_93
//
//  Created by chx on 2020/8/9.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> answers;
    bool isLegal(int num) {
        return 0 <= num && num < 256 ? true : false;
    }
    
    int to_number(int start, int end, string& s) {
        int result = 0;
        if (start != end && s[start] == '0') return -1;
        for (int i = start; i <= end; i++)
            result = result*10 + s[i] - '0';
        return result;
    }
    
    string to_ip(const vector<string> array) {
        string result = "";
        for (auto &item : array) {
            result += item + ".";
        }
        result.erase(result.end()-1);
        return result;
    }
    
    void backtracking(int start, string& s, vector<string>& result) {
        if (result.size() > 4) return;
        if (start >= s.length()) {
            if (result.size() == 4) {
                answers.push_back(to_ip(result));
            }
            return;
        }

        for (int i = start; i < s.length() && i < start+3; i++) {
            int curr = to_number(start, i, s);
            if (isLegal(curr)) {
                result.push_back(to_string(curr));
                backtracking(i+1, s, result);
                result.pop_back();
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        backtracking(0, s, result);
        return answers;
    }
};

int main(int argc, const char * argv[]) {
    Solution solve;
    string s = "010010";
    vector<string> result = solve.restoreIpAddresses(s);
    return 0;
}
