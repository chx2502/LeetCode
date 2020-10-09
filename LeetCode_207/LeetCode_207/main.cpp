//
//  main.cpp
//  LeetCode_207
//
//  Created by chx on 2020/8/4.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> hasPreCourse;
    
    bool bfs(vector<vector<int>>& graph, int target) {
        queue<int> Q;
        
        vector<int> visited(hasPreCourse.begin(), hasPreCourse.end());
        int count = 0;
        for (int i = 0; i < target; i++) if (visited[i] == 0) {
            count++;
            Q.push(i);
        }
        while (!Q.empty()) {
            int vertex = Q.front();
            
            Q.pop();
            for (auto &next : graph[vertex]) {
                visited[next]--;
                if (visited[next] == 0) {
                    Q.push(next);
                    count++;
                    if (count == target) return true;
                }
            }
        }
        return false;
    }
    
    vector<vector<int>> createGraph(vector<vector<int>> &edges, int count) {
        vector<vector<int>> result(count);
        for (auto &edge : edges) {
            result[edge[1]].push_back(edge[0]);
        }
        return result;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int size = (int)prerequisites.size();
        if (size == 0) return true;
        vector<vector<int>> graph = createGraph(prerequisites, numCourses);
        hasPreCourse.assign(numCourses, 0);
        for (int i = 0; i < size; i++) {
            hasPreCourse[prerequisites[i][0]]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (hasPreCourse[i] == 0) {
                if (bfs(graph, numCourses)) return true;
            }
        }
        return false;
    }

};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> graph = {
        {2, 0},
        {2, 1},
//        {1, 3}
    };
    bool result = s.canFinish(3, graph);
    return 0;
}
