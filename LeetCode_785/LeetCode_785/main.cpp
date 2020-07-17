//
//  main.cpp
//  LeetCode_785
//
//  Created by chx on 2020/7/16.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    vector<int> color;
    vector<bool> visited;
public:
    
    bool paint(vector<vector<int>>& graph, int x) {
        queue<int> q;
        q.push(x);
        color[x] = 1;
        while (!q.empty()) {
            int curr = q.front();
            visited[curr] = true;
            q.pop();
            for (auto i : graph[curr]) {
                if (color[i] == 0) {
                    color[i] = -color[curr];
                    q.push(i);
                } else {
                    if (color[i] == color[curr]) return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int size = (int)graph.size();
        color.assign(size, 0);
        visited.assign(size, false);
        for (int i = 0; i < size; ++i)
            if (!visited[i] && !paint(graph ,i)) return false;
        return true;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> graph = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3},
        {0, 2}
    };
    Solution s;
    bool result = s.isBipartite(graph);
    return 0;
}
