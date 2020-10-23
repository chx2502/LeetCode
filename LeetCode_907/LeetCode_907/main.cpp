//
//  main.cpp
//  LeetCode_907
//
//  Created by chx on 2020/10/20.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int size = (int)A.size();
        vector<vector<int>> dp(size, vector<int>(size, -1));
        for (int i = 0; i < size; i++) dp[i][i] = A[i];
        for (int i = 0; i < size; i++)
            for (int j = i+1; j < size; j++)
                for (int k = i; k < j; k++)
                    dp[i][j] = min(dp[i][k], dp[k+1][j]);
        int result = 0;
        int mod = 1e9+7;
        for (int i = 0; i < size; i++){
            for (int j = i; j < size; j++)
                result = (result + dp[i][j]) % mod;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> A = {3, 1, 2, 4};
    s.sumSubarrayMins(A);
    return 0;
}
