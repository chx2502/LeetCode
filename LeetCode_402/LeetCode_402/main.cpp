//
//  main.cpp
//  LeetCode_402
//
//  Created by chx on 2020/11/27.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int length = (int)num.length();
        if (length <= k) return "0";
        int p, q;
        while (k) {
            p = 0; q = 1;
            while (q < length && num[p]<= num[q]) {
                p++;
                q++;
            }
            num.erase(num.begin() + p);
            k--;
        }
        while(num.length() > 1 && num[0] == '0') num.erase(num.begin());
        return num;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string num = "10200";
    string result = s.removeKdigits(num, 1);
    return 0;
}
