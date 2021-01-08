//
//  main.cpp
//  LeeTCode_861
//
//  Created by chx on 2020/12/7.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int row, col;
        row = (int)A.size();
        col = (int)A[0].size();
        vector<bool> rowChanged(row, false);
        vector<bool> colChanged(col, false);
        
        for (int i = 0; i < row; i++) {
            if (A[i][0] == 0) {
                rowChanged[i] = true;
                for (auto &num : A[i]) num ^= 1;
            }
        }
        for (int i = 1; i < col; i++) {
            int count = 0;
            for (int j = 0; j < row; j++) {
                if (A[j][i] == 0) count++;
            }
            if (count > row-count) {
                colChanged[i] = true;
                for (int j = 0; j < row; j++) {
                    A[j][i] ^= 1;
                }
            }
        }
        int result = 0;
        for (int i = 0; i < row; i++) {
            int temp = 0;
            for (int j = 0; j < col; j++) {
                temp <<= 1;
                temp += A[i][j];
            }
            result += temp;
        }
        return result;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> A = {
        {0, 0, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 0}
    };
    int result = s.matrixScore(A);
    return 0;
}
