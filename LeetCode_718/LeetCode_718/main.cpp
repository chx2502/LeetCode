//
//  main.cpp
//  LeetCode_718
//
//  Created by chx on 2020/7/1.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int A_size = (int)A.size();
        int B_size = (int)B.size();
        int size = max(A_size, B_size);
        
        vector<vector<int>> dp(size, vector<int>(size, 0));
        int result = 0;
        for (int i = 0; i < A_size; ++i) {
            for (int j = 0; j < B_size; ++j) {
                if (A[i] == B[j]) {
                    if (i == 0 || j == 0) dp[i][j] = 1;
                    else dp[i][j] = dp[i-1][j-1] + 1;
                    int temp = dp[i][j];
                    result = result > temp ? result : temp;
                }
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> A = {1, 2, 3, 2, 1};
    vector<int> B = {3, 2, 1, 4, 7};
    
    int result = s.findLength(A, B);
    return 0;
}
