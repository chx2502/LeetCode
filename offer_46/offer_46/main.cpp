//
//  main.cpp
//  offer_46
//
//  Created by chx on 2021/4/3.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        vector<int> dp(s.length()+1, 0);
        dp[0] = dp[1] = 1;
        
        for (int i = 2; i <= s.length(); i++) {
            long curr = stol(s.substr(i-2, 2));
            if (curr >= 10 && curr <= 25) dp[i] = dp[i-2] + dp[i-1];
            else dp[i] = dp[i-1];
        }
        return dp[s.length()];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int num = 25;
    int result = s.translateNum(num);
    return 0;
}
