//
//  main.cpp
//  LeetCode_1584
//
//  Created by chx on 2021/1/19.
//

#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

class Solution {
private:
    vector<int> memory;
    vector<vector<int>> weight;
    vector<bool> visited;
public:
    int manhattanDist(int a, int b, vector<vector<int>>& points) {
        return abs(points[a][0] - points[b][0]) + abs(points[a][1] - points[b][1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = (int)points.size();
        weight.assign(n, vector<int>(n, 0));
        memory.assign(n, INT_MAX);
        for (int i = 0; i < n; i++) {
            weight[i][i] = INT_MAX;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i+1; i < n; i++) {
                int dist = manhattanDist(i, j, points);
                weight[i][j] = weight[j][i] = dist;
                memory[i] = min(memory[i], dist);
                memory[j] = min(memory[j], dist);
            }
        }
        return accumulate(memory.begin(), memory.end(), 0);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
