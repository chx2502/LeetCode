//
//  main.cpp
//  LeetCode_125
//
//  Created by chx on 2020/10/9.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left, right;
        left = 0;
        right = (int)s.length() -1;
        while (left < right) {
            char l = s[left];
            char r = s[right];
            while (!(('0' <= l && l <= '9') || ('A' <= l && l <= 'Z') || ('a' <= l && l <= 'z')) && left < right) {
                left++;
                l = s[left];
            }
            while (!(('0' <= r && r <= '9') || ('A' <= r && r <= 'Z') || ('a' <= r && r <= 'z')) && left < right) {
                right--;
                r = s[right];
            }

            if (tolower(l) != tolower(r)) return false;
            left++;
            right--;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solve;
    string s = "0P";
    bool result = solve.isPalindrome(s);
    return 0;
}
