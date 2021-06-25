#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int m, n;
public:
    int bfs(vector<vector<int>>& land, int x, int y) {
        if (x < 0 || y < 0 || x >= m || y >= n) return 0;
        if (land[x][y] != 0) return 0;
        land[x][y] = 1;
        return 1 + bfs(land, x-1, y-1) + bfs(land, x-1, y) + bfs(land, x-1, y+1) +
               bfs(land, x, y-1) + bfs(land, x, y+1) + bfs(land, x+1, y-1) +
               bfs(land, x+1, y) + bfs(land, x+1, y+1);
    }
    vector<int> pondSizes(vector<vector<int>>& land) {
        m = (int)land.size();
        n = (int)land[0].size();
        if (m == 0 || n == 0) return {};

        vector<int> result;
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (land[x][y] == 0) result.push_back(bfs(land, x, y));
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};