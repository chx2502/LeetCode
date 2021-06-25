//
//  main.cpp
//  LeetCode_363
//
//  Created by chx on 2021/4/22.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubSeqSum(vector<int>& nums, int k) {
        unsigned long size = nums.size();
        vector<int> dp(size+1, 0);
        for (int i = 1; i <= size; i++) {
            int curr = nums[i-1];
            int temp = curr + dp[i-1];
            if (temp < 0) {
                dp[i] = 0;
            } else {
                dp[i] = temp;
            }
        }
        int result = INT32_MIN;
        for (int i = 1; i <= size; i++) {
            if (dp[i] <= k) result = max(result, dp[i]);
        }
        return result;
    }
    
    void printArr(vector<int>& arr) {
        for (auto num : arr) cout << num << " ";
        cout << endl;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        unsigned long m = matrix.size();
        if (m == 0) return 0;
        unsigned long n = matrix[0].size();
        if (n == 0) return 0;
        
        vector<vector<int>> prefixSum(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (i == 0) prefixSum[i][j] = matrix[i][j];
                else prefixSum[i][j] = prefixSum[i-1][j] + matrix[i][j];
            }
        }
        int result = INT32_MIN;
        for (auto &nums : prefixSum) {
            printArr(nums);
            int temp = maxSubSeqSum(nums, k);
            cout << "temp = " << temp << endl;
            if (temp <= k) result = max(result, temp);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> matrix = {
        {2, 2, -1},
    };
    int k = 0;
    int result = s.maxSumSubmatrix(matrix, k);
    return 0;
}
