//
//  main.cpp
//  LeetCode_340
//
//  Created by chx on 2021/3/1.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findSubstr(string& s, int begin, int end, int k) {
        if (k == 0) return 0;
        if (end-begin+1 <= k) return end-begin+1;
        if (begin > end) return -1;
        
        unordered_map<char, int> charMap;
        set<char> charSet;
        int result = 0;
        for (int i = begin; i <= end; i++) {
            char c = s[i];
            charMap[c]++;
            charSet.insert(c);
            if (charSet.size() > k) {
                int next = -1;
                for (int j = begin; j < i; j++) {
                    charMap[s[j]]--;
                    if (charMap[s[j]] == 0) {
                        next = j+1;
                        break;
                    }
                }
                return max(result, findSubstr(s, next, end, k));
            } else result++;
        }
        return result;
    }
    
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        return findSubstr(s, 0, (int)s.length()-1, k);
    }
};

int main(int argc, const char * argv[]) {
    string s = "eceba";
    int k = 2;
    Solution solve;
    int result = solve.lengthOfLongestSubstringKDistinct(s, k);
    return 0;
}
