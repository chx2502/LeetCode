//
//  main.cpp
//  LeetCode_1030
//
//  Created by chx on 2020/11/17.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int distance(int r, int c, int r0, int c0) {
        return abs(r-r0) + abs(c-c0);
    }
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        auto cmp = [&](vector<int>& cordinate1, vector<int>& cordinate2) {
            int r1 = cordinate1[0];
            int c1 = cordinate1[1];
            int r2 = cordinate2[0];
            int c2 = cordinate2[1];
            return distance(r1, c1, r0, c0) > distance(r2, c2, r0, c0);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                pq.push({r, c});
            }
        }
        vector<vector<int>> result;
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
