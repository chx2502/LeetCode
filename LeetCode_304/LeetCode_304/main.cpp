//
//  main.cpp
//  LeetCode_304
//
//  Created by chx on 2020/10/22.
//

#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
private:
    vector<vector<int>> M;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        M.resize(matrix.size());
        for (int i = 0; i < M.size(); i++) {
            M[i].assign(matrix[i].begin(), matrix[i].end());
            for (int j = 1; j < M[i].size(); j++)
                M[i][j] += M[i][j-1];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = 0;
        for (int r = row1; r <= row2; r++) {
            if (col1 == 0) result += M[r][col2];
            else result += M[r][col2] - M[r][col1-1];
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
