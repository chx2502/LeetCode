//
//  main.cpp
//  LeetCode_131_分割回文串
//
//  Created by chx on 2020/4/15.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int length = (int)s.length();
        if (length == 0) return false;
        if (length == 1) return true;
        int i, j;
        i = 0;
        j = length-1;
        while (i < length && j >=0 && i < j && s[i] == s[j]) {
            i++;
            j--;
        }
        if (i < j) return false;
        else return true;
    }
    
    void backTracking(
                      int begin, string s, int length,
                      vector<string>& curr_loop,
                      vector<vector<string>>& result
                      )
    {
        if (begin == length) {
            result.push_back(curr_loop);
            return;
        }
        for (int i = 1; i <= length-begin; ++i) {
            // string.str(begin, count) 注意第二个参数是子字符串的字符数量
            string curr = s.substr(begin, i);
            if (isPalindrome(curr)) {
                curr_loop.push_back(curr);
                backTracking(begin+i, s, length, curr_loop, result);
                curr_loop.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        int length = (int)s.length();
        if (length == 0) return result;
        vector<string> curr_loop;
        backTracking(0, s, length, curr_loop, result);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string str = "abb";
    vector<vector<string>> result = s.partition(str);
    return 0;
}
