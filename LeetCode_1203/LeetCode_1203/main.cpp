//
//  main.cpp
//  LeetCode_1203
//
//  Created by chx on 2021/1/12.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>

using namespace std;

class Solution {
private:
    unordered_map<int, vector<int>> graph;
    vector<int> indegree;
    vector<set<int>> taskSet;
    vector<bool> completed;
    int taskCount;
    
    void init(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        indegree.assign(n, 0);
        taskSet.assign(m, set<int>());
        completed.assign(n, false);
        taskCount = n;
        for (int i = 0; i < n; i++) {
            graph[i] = vector<int>();
        }
        for (int i = 0; i < n; i++) {
            if (group[i] != -1) taskSet[group[i]].insert(i);
            if (beforeItems[i].size()) {
                for (auto &task : beforeItems[i]) {
                    graph[task].push_back(i);
                    indegree[i]++;
                }
            }
        }
    }
    
    void proccess(int x) {
        for (auto &next : graph[x]) indegree[next]--;
        completed[x] = true;
    }
    
    int getTask() {
        for (auto &s : taskSet) {
            if (s.empty()) {
                newTask();
            }
            for (auto task : s) {
                if (indegree[task] == 0) {
                    s.erase(s.find(task));
                    return task;
                }
            }
        }
        return -1;
    }
    
    bool newTask() {
        for (int i = 0; i < taskCount; i++) {
            if (indegree[i] == 0 && !completed[i]) {
                for (auto &s : taskSet) {
                    if (s.empty()) {
                        s.insert(i);
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        init(n, m, group, beforeItems);
        vector<int> result;
        while (result.size() < n) {
            int task = getTask();
            if (task != -1) {
                proccess(task);
                result.push_back(task);
            } else {
                if (!newTask()) return {};
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> group = {-1, -1, 1, 0, 0, 1, 0, -1};
    vector<vector<int>> beforeItems = {
        {},
        {6},
        {5},
        {6},
        {3, 6},
        {},
        {},
        {},
    };
    int n = 8;
    int m = 2;
    vector<int> result = s.sortItems(n, m, group, beforeItems);
    return 0;
}
