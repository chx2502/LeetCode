//
//  main.cpp
//  LeetCode_261
//
//  Created by chx on 2021/4/29.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    // root[x] 记录编号为 x 的节点的根节点
    vector<int> root;
    
    int Find(int x) {
        while (root[x] != x) {
            x = root[x];
            // 路径压缩
            root[x] = root[root[x]];
        }
        return x;
    }
    bool Union(int A, int B) {
        int rootA, rootB;
        rootA = Find(A);
        rootB = Find(B);
        // rootA == rootB 时构成环，破坏条件2
        // rootA != A && rootB != B 说明 A 和 B 都有父节点，破坏条件3
        if (rootA == rootB || (rootA != A && rootB != B)) {
            return false;
        }
        if (rootA == A && rootB != B) root[A] = B;
        else root[B] = A;
        return true;
        
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // 判断条件1
        if (edges.size() < n-1) return false;
        root.assign(n, 0);
        
        for (int i = 0; i < n; i++) root[i] = i;
        for (auto &edge : edges) {
            // 条件2 或 条件3 被破坏则返回 false
            if (!Union(edge[0], edge[1])) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {1, 4}, {1, 3}
    };
    int n = 5;
    bool result = s.validTree(n, edges);
    return 0;
}
