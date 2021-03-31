//
//  main.cpp
//  LeetCode_395
//
//  Created by chx on 2021/2/27.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int left = 0;
        int right = (int)s.length()-1;
        
        if (right - left + 1 < k) return 0;
        
        unordered_map<char, int> memory;
        set<char> charSet;
        
        for (auto &c : s) {
            if (memory.count(c) == 0) charSet.insert(c);
            memory[c]++;
            if (memory[c] == k) charSet.erase(c);
        }
        if (charSet.size() == 0) return right-left+1;
        
        
        for (int i = left; i <= right; i++) {
            char c = s[i];
            if (charSet.count(c)) {
                return max(longestSubstring(s.substr(left, i-left), k), longestSubstring(s.substr(i+1, right-i), k));
            }
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string ss = "aaabb";
    int result = s.longestSubstring(ss, 3);
    return 0;
}
