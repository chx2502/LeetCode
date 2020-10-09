//
//  main.cpp
//  LeetCode_双周赛33
//
//  Created by chx on 2020/8/22.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    string split(char splitChar, int count, int n) {
        string result = "";
        string n_str = to_string(n);
        int length = (int)n_str.length();
        stack<char> stk;
        bool flag = false;
        for (int i = length-1; i >= 0; i--) {
            if (flag) {
                result = splitChar + result;
                flag = false;
            }
            stk.push(n_str[i]);
            if (stk.size() == count) {
                flag = true;
                string temp = "";
                while(!stk.empty()) {
                    temp += stk.top();
                    stk.pop();
                }
                result = temp + result;
            }
        }
        string temp = "";
        while(!stk.empty()) {
            temp += stk.top();
            stk.pop();
        }
        result = temp + result;
        return result;
    }
    
    string thousandSeparator(int n) {
        return split('.', 3, n);
    }
    
    vector<bool> visited;
    set<int> node_set;
    
    vector<vector<int>> createGrapgh(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto &pair : edges) {
            graph[pair[0]].push_back(pair[1]);
        }
        return graph;
    }
    
    void dfs(int x, vector<vector<int>>& graph) {
        visited[x] = true;
        for (auto next : graph[x]) {
            if (node_set.find(next) != node_set.end()) node_set.erase(next);
            if (!visited[next]) dfs(next, graph);
        }
    }
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        visited.assign(n, false);
        vector<vector<int>> graph = createGrapgh(n, edges);
        vector<int> result;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                node_set.insert(i);
                dfs(i, graph);
            }
        }
        
        for (auto num : node_set) result.push_back(num);
        sort(result.begin(), result.end(), less<int>());
        return result;
    }
    
    vector<pair<int, int>> around {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };
    
    vector<vector<bool>> watched;
    int road;
    
    bool dfs(int row, int col, int m, int n, pair<int, int>& pre, vector<vector<char>>& grid, pair<int, int>& start) {
        if (row < 0 || col < 0 || row >= m || col >= n) return false;
        if (grid[row][col] != grid[pre.first][pre.second]) return false;
        if (row == start.first && col == start.second && road >= 4) return true;
        
        watched[row][col] = true;
        road++;
        for (auto &next : around) {
            int next_r = row + next.first;
            int next_c = col + next.second;
            if (next_r == pre.first && next_c == pre.second) continue;
            pair<int, int> curr = {row, col};
            if (dfs(next_r, next_c, m, n, curr, grid, start)) {
                return true;
            }
        }
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        watched.assign(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!watched[i][j]) {
                    int count = 0;
                    for (auto &next : around) {
                        int next_r = i + next.first;
                        int next_c = j + next.second;
                        if (next_r < 0 || next_c < 0 || next_r >=m || next_c >= n) continue;
                        if (grid[next_r][next_c] == grid[i][j]) count++;
                    }
                    road = 0;
                    pair<int, int> curr = {i, j};
                    if (count > 1 && dfs(i, j, m, n, curr, grid, curr)) return true;
                    else watched[i][j] = true;
                }
            }
        }
        return false;
    }
    
    
};

int main(int argc, const char * argv[]) {
    Solution s;
    int n = 123456;
    string result = s.thousandSeparator(n);
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {2, 5}, {3, 4},{4, 2}
    };
    vector<int> res2 = s.findSmallestSetOfVertices(6, edges);
    vector<vector<char>> grid = {
        {'a','b','b'},
        {'b', 'z', 'b'},
        {'b', 'b', 'a'},
//        {'f', 'c', 'c', 'c'}
    };
    bool res3 = s.containsCycle(grid);
    return 0;
}
