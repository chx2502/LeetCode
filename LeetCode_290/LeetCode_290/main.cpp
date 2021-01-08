//
//  main.cpp
//  LeetCode_290
//
//  Created by chx on 2020/12/16.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
//    vector<string> split(string s, string delim) {
//        char *writable = new char[s.size()];
//        copy(s.begin(), s.end(), writable);
//        vector<string> res;
//        char *token = strtok(writable, delim.c_str());
//        while (token != NULL) {
//            res.push_back(token);
//            token = strtok(NULL, delim.c_str());
//        }
//        delete [] writable;
//        return res;
//    }
    
    bool wordPattern(string pattern, string s) {
        int length = (int)pattern.length();
       
        vector<string> words;
        int start = 0;
        // 手动按空格分割
        while (start < s.length()) {
            int end = (int)s.find_first_of(" ", start, 1);
            string word;
            if (end == string::npos) {
                word = s.substr(start, s.length()-start);
                start = (int)s.length();
            } else {
                word = s.substr(start, end-start);
                start = end+1;
            }
            words.push_back(word);
        }
//        words = split(s, " ");
        unordered_map<char, string> patternDict;
        unordered_map<string, char> wordDict;
        if (words.size() != length) return false;
        for (int i = 0; i < length; i++) {
            char c = pattern[i];
            string word = words[i];
            if (patternDict.find(c) == patternDict.end() && wordDict.find(word) != wordDict.end()) return false;
            if (patternDict.find(c) == patternDict.end()) {
                patternDict[c] = word;
                wordDict[word] = c;
            } else {
                if (patternDict[c].compare(word) != 0) return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution solve;
    string pattern = "abc";
    string s = "dog cat dog";
    bool result = solve.wordPattern(pattern, s);
    return 0;
}
