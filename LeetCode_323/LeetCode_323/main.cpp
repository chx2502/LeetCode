//
//  main.cpp
//  LeetCode_323
//
//  Created by chx on 2021/4/29.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> root;
    vector<int> size;
    int groupCount;
    void UnionFindSetInit(int n) {
        root.assign(n, 0);
        for (int i = 0; i < n; i++) root[i] = i;
        size.assign(n, 1);
        groupCount = n;
    }
    
    int Find(int x) {
        while (x != root[x]) {
            root[x] = root[root[x]];
            x = root[x];
        }
        return x;
    }
    
    void Union(int A, int B) {
        int rootA = Find(A);
        int rootB = Find(B);
        if (rootA == rootB) return;
        if (size[rootA] >= size[rootB]) {
            root[rootB] = rootA;
            size[rootA] += size[rootB];
        } else {
            root[rootA] = rootB;
            size[rootB] += size[rootA];
        }
        groupCount--;
    }
    
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFindSetInit(n);
        for (auto &edge : edges) {
            Union(edge[0], edge[1]);
        }
        return groupCount;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> edges = {
        {5, 6}, {0, 2}, {1, 7}, {5, 9}, {1, 8},
        {3, 4}, {0, 6}, {0, 7}, {0, 3}, {8, 9}
    };
    int n = 10;
    int result = s.countComponents(n, edges);
    return 0;
}
