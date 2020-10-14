//
//  main.cpp
//  LeetCode_547
//
//  Created by chx on 2020/10/10.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
private:
    vector<bool> visited;
public:
    void bfs(int x, vector<vector<int>>& M, int N) {
        queue<int> Q;
        Q.push(x);
        while (!Q.empty()) {
            int curr = Q.front();
            visited[curr] = true;
            Q.pop();
            for (int i = 0; i < N; i++) {
                if (M[curr][i] == 1 && !visited[i]) Q.push(i);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int N = (int)M.size();
        if (N == 0) return 0;
        visited.assign(N, false);
        int result = 0;
        for (int i = 0; i < N; i++) {
            if (visited[i]) continue;
            bfs(i, M, N);
            result += 1;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
