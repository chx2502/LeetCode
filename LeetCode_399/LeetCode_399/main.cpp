//
//  main.cpp
//  LeetCode_399
//
//  Created by chx on 2021/1/6.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

typedef unordered_map<string, unordered_map<string, double>> Graph;
typedef unordered_map<string, vector<string>> NodeMap;

class Solution {
private:
    void Floyd(Graph G) {
        
    }
    pair<Graph, NodeMap> createGraph(vector<vector<string>>& equations, vector<double>& values) {
        Graph G;
        NodeMap NM;
        int size = (int)equations.size();
        for (int i = 0; i < size; i++) {
            string left = equations[i][0];
            string right = equations[i][1];
            double value = values[i];
            G[left][left] = 1.0;
            G[right][right] = 1.0;
            G[left][right] = value;
            G[right][left] = 1.0 / value;
            NM[left].push_back(right);
            NM[right].push_back(left);
        }
        return pair<Graph, NodeMap>(G, NM);
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        pair<Graph, NodeMap> GN = createGraph(equations, values);
        Graph G = GN.first;
        NodeMap NM = GN.second;
        vector<double> result;
        
        for (auto &q : queries) {
            string left = q[0];
            string right = q[1];
            result.push_back(G[left][right]);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<string>> e = {
        {"a", "b"},
        {"e", "f"},
        {"b", "e"}
    };
    vector<double> v = { 3.4, 1.4, 2.3 };
    vector<vector<string>> q = {
        {"b", "a"},
        {"a", "f"},
        {"f", "f"},
        {"e", "e"},
        {"c", "c"},
        {"a", "c"},
        {"f", "e"}
    };
    vector<double> result = s.calcEquation(e, v, q);
    return 0;
}
