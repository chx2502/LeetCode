//
//  main.cpp
//  LeetCode_210
//
//  Created by chx on 2020/11/12.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    int count;
    vector<bool> visited;
    vector<int> result;
    vector<int> indegree;
public:
    vector<vector<int>> createGraph(vector<vector<int>>& prerequisites, int numCourses) {
        vector<vector<int>> graph(numCourses);
        for (auto item : prerequisites) {
            graph[item[1]].push_back(item[0]);
            indegree[item[0]]++;
        }
        return graph;
    }
    
    void bfs(vector<vector<int>>& graph, int x) {
        queue<int> q;
        q.push(x);
        while (!q.empty()) {
            int curr = q.front();
            visited[curr]= true;
            q.pop();
            count--;
            result.push_back(curr);
            for (auto &next : graph[curr]) {
                indegree[next]--;
                if (!visited[next] && indegree[next] == 0) q.push(next);
            }
        }
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 0) return {};
        
        count = numCourses;
        visited.assign(numCourses, false);
        indegree.assign(numCourses, 0);
        
        vector<vector<int>> graph = createGraph(prerequisites, numCourses);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && indegree[i] == 0) bfs(graph, i);
        }
        return count == 0 ? result : vector<int>(0);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int numCourses = 4;
    vector<vector<int>> prerequisites = {
        {1, 0}, {2, 0}, {3, 1}, {3, 2}
    };
    vector<int> result = s.findOrder(numCourses, prerequisites);
    return 0;
}
