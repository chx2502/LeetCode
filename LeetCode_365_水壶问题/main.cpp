#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    bool dfs(int x, int y, int z, int left, int right) {
        if (dp[left][right] != 2) return false;
        if (left == z || right == z) {
            dp[left][right] = 1;
            return true;
        }
        dp[left][right] = 0;
        int left_leftToRight = left - (y-right);
        int right_leftToRight = left+right < y ? left + right : y;
        int left_rightToleft = left+right < x ? left + right : x;
        int right_rightToleft = right - (x-left);
        return dfs(x, y, z, x, 0) || dfs(x, y, z, 0, y) || dfs(x, y, z, left_leftToRight, right_leftToRight) || dfs(x, y, z, left_rightToleft, right_rightToleft);
    }
    bool canMeasureWater(int x, int y, int z) {
        for (int i = 0; i < x; i++) dp.push_back(vector<int>(y, 2));
        return dfs(x, y, z, 0, 0);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
