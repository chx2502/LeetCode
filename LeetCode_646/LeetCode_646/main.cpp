//
//  main.cpp
//  LeetCode_646
//
//  Created by chx on 2021/3/7.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int size = (int)pairs.size();
        if (size == 0) return 0;
        
        auto cmp = [&](const vector<int>& a, const vector<int>& b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
        };
        sort(pairs.begin(), pairs.end(), cmp);
        
        int result = 0;
        vector<int> dp(size, 1);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1]) dp[i] = max(dp[i], dp[j]+1);
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
