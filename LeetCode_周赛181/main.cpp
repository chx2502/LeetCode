#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:

    void buildBoundary(vector<vector<int>>& grid, int m, int n) {
        vector<int> horizon(n, 0);
        grid.insert(grid.begin(), horizon);
        grid.push_back(horizon);
        for (auto &array : grid) {
            array.insert(array.begin(), 0);
            array.push_back(0);
        }
        return;
    }

    const int up = 0;
    const int down = 1;
    const int left = 2;
    const int right = 3;
    vector<vector<int>> help = {
            {2, 3, 4},
            {2, 5, 6},
            {1, 4, 6},
            {1, 3, 5}
    };

    vector<vector<bool>> visited;

    bool dfs(vector<vector<int>>& grid, int row, int col, int m, int n) {
        if (row < 0 || col < 0 || row == m || col == n) return false;
        if (visited[row][col]) return false;
        if (row == m-1 && col == n-1) return true;
        int pipe = grid[row][col];
        visited[row][col] = true;
        bool leftRes, rightRes, upRes, downRes;
        leftRes = rightRes = upRes = downRes = false;
        int leftPipe, rightPipe, upPipe, downPipe;
        if (pipe == 1) {
            leftPipe = grid[row][col-1];
            rightPipe = grid[row][col+1];
            for (auto &num : help[left]) {
                if (num == leftPipe) {
                    leftRes = dfs(grid, row, col-1, m, n);
                    break;
                }
            }

            for (auto &num : help[right]) {
                if (num == rightPipe) {
                    rightRes = dfs(grid, row, col+1, m, n);
                    break;
                }
            }
        }
        if (pipe == 2) {
            upPipe = grid[row-1][col];
            downPipe = grid[row+1][col];
            for (auto &num : help[up]) {
                if (num == upPipe) {
                    leftRes = dfs(grid, row-1, col, m, n);
                    break;
                }
            }

            for (auto &num : help[down]) {
                if (num == downPipe) {
                    rightRes = dfs(grid, row+1, col, m, n);
                    break;
                }
            }
        }
        if (pipe == 3) {
            leftPipe = grid[row][col-1];
            downPipe = grid[row+1][col];
            for (auto &num : help[left]) {
                if (num == leftPipe) {
                    leftRes = dfs(grid, row, col-1, m, n);
                    break;
                }
            }

            for (auto &num : help[down]) {
                if (num == downPipe) {
                    downRes = dfs(grid, row+1, col, m, n);
                    break;
                }
            }
        }
        if (pipe == 4) {
            rightPipe = grid[row][col+1];
            downPipe = grid[row+1][col];
            for (auto &num : help[right]) {
                if (num == rightPipe) {
                    rightRes = dfs(grid, row, col+1, m, n);
                    break;
                }
            }

            for (auto &num : help[down]) {
                if (num == downPipe) {
                    downRes = dfs(grid, row+1, col, m, n);
                    break;
                }
            }
        }
        if (pipe == 5) {
            leftPipe = grid[row][col-1];
            upPipe = grid[row-1][col];
            for (auto &num : help[left]) {
                if (num == leftPipe) {
                    leftRes = dfs(grid, row, col-1, m, n);
                    break;
                }
            }

            for (auto &num : help[up]) {
                if (num == upPipe) {
                    upRes = dfs(grid, row-1, col, m, n);
                    break;
                }
            }
        }
        if (pipe == 6) {
            rightPipe = grid[row][col+1];
            upPipe = grid[row-1][col];
            for (auto &num : help[right]) {
                if (num == rightPipe) {
                    rightRes = dfs(grid, row, col+1, m, n);
                    break;
                }
            }

            for (auto &num : help[up]) {
                if (num == upPipe) {
                    upRes = dfs(grid, row-1, col, m, n);
                    break;
                }
            }
        }
        return leftRes || rightRes || upRes || downRes;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        if (m == 0) return false;
        int n = (int)grid[0].size();
        buildBoundary(grid, m, n);
        for (int i = 0; i <= m+1; ++i) {
            vector<bool> temp(n+2, false);
            visited.push_back(temp);
        }
        return dfs(grid, 1, 1, m+1, n+1);
    }

    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {

        int size = (int)nums.size();


        vector<int> result(size, -1);
        if (size == 0) result;

        vector<int> idxMap(size, 0);
        for (auto &idx : index) {
            idxMap[idx]++;
        }
        int bias = 0;
        for (auto &idx : index) {
            idx = idx + idxMap[idx] -1 + bias;
            if (idxMap[idx] > 1) {
                idxMap[idx]--;
                bias++;
            }
        }
        for (int i = 0; i < size; ++i) {
            result[index[i]] = nums[i];
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0, 1, 2, 3, 4};
    vector<int> index = {0, 1, 2, 2, 1};
    vector<int> res = s.createTargetArray(nums, index);
    vector<vector<int>> grid = {
            {1, 1, 2},
//            {6, 5, 2}
    };
    bool result = s.hasValidPath(grid);
    return 0;
}
