//
//  main.cpp
//  LeetCode_1035
//
//  Created by chx on 2020/7/22.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int size_A = (int)A.size();
        int size_B = (int)B.size();
        if (size_A == 0 || size_B == 0) return 0;

        // vector<vector<int>> dp(size_A+1, vector<int>(size_B+1, 0));

        int dp_ij = 0;
        vector<int> dp(size_B+1, 0);

        for (int i = 1; i <= size_A; i++) {
            dp_ij = dp[0];
            for (int j = 1; j <= size_B; j++) {
                int temp = dp[j];
                // if (A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                // else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (A[i-1] == B[j-1]) dp[j] = dp_ij+1;
                else dp[j] = max(dp[j], dp[j-1]);
                dp_ij = temp;
            }
        }
        return dp[size_B];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> A = {1, 4, 2};
    vector<int> B = {1 ,2 ,4};
    int result = s.maxUncrossedLines(A, B);
    return 0;
}
