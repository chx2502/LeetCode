//
//  main.cpp
//  LeetCode_834
//
//  Created by chx on 2020/10/6.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <numeric>

using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<int> distSum;
    vector<int> nodeCount;
    vector<bool> visited;
    
    int count = 0;
    void postOrderTraversal(int root) {
        visited[root] = true;
        for (auto child : graph[root]) {
            if (visited[child]) continue;
            postOrderTraversal(child);
            int temp = nodeCount[child];
            nodeCount[root] += temp;
            distSum[root] += temp + distSum[child];
        }
    }
    
    void preOrderTraversal(int root, int N) {
        visited[root] = true;
        for (auto child : graph[root]) {
            if (visited[child]) continue;
            int temp = nodeCount[child];
            distSum[child] = distSum[root] - temp + (N - temp);
            preOrderTraversal(child, N);
        }
    }
    
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        visited.assign(N, false);
        distSum.assign(N, 0);
        nodeCount.assign(N, 1);
        for (auto &edge : edges) {
            int u, v;
            u = edge[0];
            v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        postOrderTraversal(0);
        visited.assign(N, false);
        preOrderTraversal(0, N);
        return distSum;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> edges = {
        {0,1},
        {0,2},
        {2,3},
        {2,4},
        {2,5}
    };
    int N = 6;
    vector<int> result = s.sumOfDistancesInTree(N, edges);
    for (int i = 0; i < N; i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}
