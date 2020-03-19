#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * 常规思路，注意处理越界即可。
     * 卷积法和前缀和法待学习。
     */
    int sumSurround(vector<vector<int>>& mat, int row, int col, int K) {
        int result = 0;
        int m = (int)mat.size();
        int n = (int)mat[0].size();
        for (int i = row-K; i <= row+K; ++i) {
            if (i < 0) continue;
            if (i >= m) break;
            for (int j = col-K; j <= col+K; ++j) {
                if (j < 0 ) continue;
                if (j >= n) break;
                else result += mat[i][j];
            }
        }
        return result;
    }

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        vector<vector<int>> result;
        int m = (int)mat.size();
        if (m == 0) result;
        int n = (int)mat[0].size();
        if (n == 0) return result;
        // 单独处理 K 范围包含整个矩阵的情况
        if (K + 1 >= m) {
            int sum = sumSurround(mat, m/2, n/2, K);
            for (int i = 0; i < m; ++i)
                result.push_back(vector<int>(n, sum));
            return result;
        }

        for (int row = 0; row < m; ++row) {
            vector<int> temp;
            for (int col = 0; col <n; ++col) {
                temp.push_back(sumSurround(mat, row, col, K));
            }
            result.push_back(temp);
        }
        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
