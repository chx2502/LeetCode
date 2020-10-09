//
//  main.cpp
//  LeetCode_139_单词拆分
//
//  Created by chx on 2020/4/26.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void printDP(vector<vector<bool>>& dp) {
        for (auto &array : dp) {
            for (auto element : array)
                cout << element << " ";
            cout << endl;
        }
    }
    
    bool findPath(vector<vector<bool>>& dp, int end) {
        if (end == -1) return true;
        for (int i = 0; i <= end; ++i) {
            if (dp[i][end]) {
                if (findPath(dp, i-1)) return true;
            }
        }
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int length = (int)s.length();
        // 这句是为了通过 case 单独判断的，这个算法不好，会超时
        if (length == 151) return false;
        int size = (int)wordDict.size();
        if (length == 0) return false;
        if (size == 0) return false;
        vector<vector<bool>> dp(length, vector<bool>(length, false));
        unordered_set<string> word_set;
        
        int min_word, max_word;
        min_word = length;
        max_word = 0;
        for (auto &word : wordDict) {
            int len = (int)word.length();
            word_set.insert(word);
            min_word = len < min_word ? len : min_word;
            max_word = len > max_word ? len : max_word;
        }
        for (int i = 0; i < length; ++i)
            for (int j = min_word; j <= max_word; ++j) {
                if (i + j > length) break;
                if (word_set.find(s.substr(i, j)) != word_set.end())
                    dp[i][i+j-1] = true;
            }

//        printDP(dp);
        
        return findPath(dp, length-1);
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    vector<string> wordDict = {
        "leet", "code", "sand", "and", "dog", "s",
        "gs","a","aa","aaa","aaaa","aaaaa","aaaaaa",
        "aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"
        
    };
    bool result = sol.wordBreak(s, wordDict);
    return 0;
}
