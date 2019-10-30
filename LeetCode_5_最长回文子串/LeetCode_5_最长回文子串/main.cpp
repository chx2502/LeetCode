//
//  main.cpp
//  LeetCode_5_最长回文子串
//
//  Created by chx on 2019/10/28.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <string>


using namespace std;

class Solution {
public:
    int length_of_Palindrome(int left, int right, string s) {
        unsigned long length = s.size();
        while (left >= 0 && right < length && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        unsigned long length = s.size();
        if (length == 1) return s;
        unsigned long start, end;
        start = end = 0;
        for (int i = 0; i < length; i++) {
            int palindrome_len_1 = length_of_Palindrome(i, i, s);
            int palindrome_len_2 = length_of_Palindrome(i, i+1, s);
            int max_len = palindrome_len_1 > palindrome_len_2 ? palindrome_len_1 : palindrome_len_2;
            if (max_len > end - start) {
                start = i - (max_len - 1) / 2;
                end = i + max_len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    string str = "bb";
    string result = s.longestPalindrome(str);
    cout << result;
    return 0;
}
