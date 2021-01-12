//
//  main.cpp
//  LeetCode_684
//
//  Created by chx on 2021/1/11.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> root;
    vector<int> weight;
    int findRoot(int x) {
        while (x != root[x]) {
            root[x] = root[root[x]];
            x = root[x];
        }
        return x;
    }
    
    void connect(int a, int b) {
        int rootA = findRoot(a);
        int rootB = findRoot(b);
        if (rootA == rootB) return;

        root[rootB] = rootA;
        weight[rootA] += weight[rootB];
    }
    void initializeUF(int N) {
        root.assign(N, -1);
        weight.assign(N, 1);
        for (int i = 0; i < N; i++) {
            root[i] = i;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> result;
        initializeUF(edges.size());
        for (auto &edge : edges) {
            int u = edge[0]-1;
            int v = edge[1]-1;
            int pre = weight[findRoot(u)];
            connect(u, v);
            int after = weight[findRoot(u)];
            if (pre == after) result = edge;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> edges = {
        {1, 2},
        {1, 3},
        {2, 3},
    };
    vector<int> result = s.findRedundantConnection(edges);
    return 0;
}
