//
//  main.cpp
//  LeetCode_91
//
//  Created by chx on 2021/1/4.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
    unordered_map<string, int> memory;
    int result = 0;
public:
    int numDecodings(string s) {
        unsigned long length = s.length();
        vector<int> dp(length+1, 0);
        s.insert(s.begin(), '/');
        dp[0] = 1;
        for (int i = 1; i <= length; i++) {
            int a = s[i] - '0';
            int b = (s[i-1] - '0') * 10 + a;
            if (a >= 1 && a <= 9) dp[i] = dp[i-1];
            if (10 <= b && b <=26) dp[i] += dp[i-2];
        }
        return dp[length];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string ss = "10";
    int result = s.numDecodings(ss);
    return 0;
}
