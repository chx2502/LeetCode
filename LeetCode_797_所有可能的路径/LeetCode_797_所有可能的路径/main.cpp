//
//  main.cpp
//  LeetCode_797_所有可能的路径
//
//  Created by chx on 2019/12/1.
//  Copyright © 2019 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     惊了，写成这样也能过？？？
     递归实现，先算了各个点的可达性，极大地拖慢了速度。
     **/
    bool havePath(vector<vector<int>>& graph, int a, int b, vector<bool>& map) {
        if (a == b) {
            map[a] = true;
            return true;
        }
        
        bool flag = false;
        for (auto &next : graph[a]) {
            if (map[next]) flag = true;
            else if (havePath(graph, next, b, map)) {
                flag = true;
            }
        }
        map[a] = flag;
        return flag;
    }
    
    vector<vector<int>> allPaths(vector<vector<int>>& graph, int a, int b, vector<bool> map) {
        vector<vector<int>> ret;
        if (!map[a]) return ret;
        if (a == b) return {{b}};
        for (auto &next : graph[a]) {
            vector<vector<int>> paths;
            if (map[next]) {
                paths = allPaths(graph, next, b, map);
                if (!paths.empty()) {
                    for (auto &array : paths) {
                        array.insert(array.begin(), a);
                        ret.push_back(array);
                    }
                }
            }
        }
        return ret;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        const int vertex_num = (int)graph.size();
        vector<bool> map(vertex_num, false);
        map[0] = havePath(graph, 0, vertex_num-1, map);
        return allPaths(graph, 0, vertex_num-1, map);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};
    vector<vector<int>> result = s.allPathsSourceTarget(graph);
    return 0;
}
