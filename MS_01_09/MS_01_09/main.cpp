//
//  main.cpp
//  MS_01_09
//
//  Created by chx on 2021/4/27.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
//    bool isFlipedString(string s1, string s2) {
//        unsigned long len = s1.length();
//        if (len != s2.length()) return false;
//        if (s1.compare(s2) == 0) return true;
//
//        for (int k = 1; k < len; k++) {
//            string left1 = s1.substr(0, k);
//            string right1 = s1.substr(k, len-k);
//            string left2 = s2.substr(0, len-k);
//            string right2 = s2.substr(len-k, k);
//
//            if (left1.compare(right2) == 0 && right1.compare(left2) == 0) return true;
//        }
//        return false;
//    }
    
    bool isFlipedString(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        s2 = s2 + s2;
        return s2.find(s1) != -1;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string s1 = "waterbottle";
    string s2 = "erbottlewat";
    bool result = s.isFlipedString(s1, s2);
    return 0;
}
