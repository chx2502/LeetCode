#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> root;
    vector<int> groupSize;
    int groupCount;
    int redundant;
    bool isUnion (int x, int y) {
        return Find(x) == Find(y);
    }
    void Union(int x, int y) {
        int rootX = Find(x);
        int rootY = Find(y);
        if (rootX == rootY) {
            redundant++;
            return;
        }
        if (groupSize[rootX] < groupSize[rootY]) {
            swap(rootX, rootY);
        }
        root[rootY] = rootX;
        groupSize[rootX] += groupSize[rootY];
        groupCount--;
    }
    int Find(int x) {
        while (x != root[x]) { 
            root[x] = root[root[x]];
            x = root[x];
        }
        return x;
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        root.assign(n, -1);
        groupSize.assign(n, 1);
        for (int i = 0; i < n; i++) root[i] = i;
        redundant = 0;
        groupCount = n;
        for (auto const &conn : connections) {
            int x = conn[0];
            int y = conn[1];
            Union(x, y);
        }
        printf("redundant = %d, groupCount = %d\n", redundant, groupCount);
        return groupCount-1 <= redundant ? groupCount-1 : -1; 
    }
};
