//
//  main.cpp
//  LeetCode_685
//
//  Created by chx on 2020/9/17.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    bool bfs(vector<vector<int>>& graph, int x, int N) {
        queue<int> Q;
        Q.push(x);
        vector<bool> visited(N+1, false);
        int count = 0;
        while (!Q.empty()) {
            int v = Q.front();
            visited[v] = true;
            Q.pop();
            count++;
            for (int i = 1; i <= N; i++) {
                if (graph[v][i] && !visited[i]) Q.push(i);
            }
        }
        return count == N;
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        unordered_set<int> vertex_set;
        unordered_map<int, int> inDegree_map;
        vector<vector<int>> graph;
        
        for (auto &edge : edges) {
            inDegree_map[edge[1]] += 1;
            for (auto &vertex : edge)
                vertex_set.insert(vertex);
        }
        int N = (int)vertex_set.size();
        graph.assign(N+1, vector<int>(N+1, 0));
        
        for (auto &edge : edges) {
            graph[edge[0]][edge[1]] = 1;
        }
        for (int i = (int)edges.size()-1; i >= 0; i--) {
            int u, v;
            u = edges[i][0];
            v = edges[i][1];
            graph[u][v] = 0;
            inDegree_map[v] -= 1;
            int enter_point = 0;
            int count = 0;
            for (auto item : vertex_set) {
                if (inDegree_map[item] == 0) {
                    count++;
                    if (count > 1) {
                        enter_point = 0;
                        break;
                    }
                    enter_point = item;
                }
            }
            if (enter_point != 0) {
                if (bfs(graph, enter_point, N)) return {u, v};
            }
            graph[u][v] = 1;
            inDegree_map[v] += 1;
        }
        return {};
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> edges = {
        {1, 2},
        {1, 3},
        {2, 3},
    };
    vector<int> result = s.findRedundantDirectedConnection(edges);
    return 0;
}
