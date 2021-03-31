//
//  main.cpp
//  LeetCode_947
//
//  Created by chx on 2021/1/15.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
private:
    unordered_map<int, int> outDegree;
    unordered_map<int, int> rowMap;
    unordered_map<int, int> colMap;
    int getStoneKey(vector<int>& stone) {
        return stoi(to_string(stone[0]) + to_string(stone[1]));
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        int result = 0;
        auto compare = [&](vector<int>& stoneA, vector<int>& stoneB) {
            return outDegree[getStoneKey(stoneA)] < outDegree[getStoneKey(stoneB)];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);
        for (auto &stone : stones) {
            int row = stone[0];
            int col = stone[1];
            int key = getStoneKey(stone);
            if (rowMap.find(row) == rowMap.end()) {
                rowMap[row]++;
            } else {
                outDegree[key] += rowMap[row];
                rowMap[row]++;
            }
            if (colMap.find(col) == colMap.end()) {
                colMap[col]++;
            } else {
                outDegree[key] += colMap[col];
                colMap[col]++;
            }
            if (outDegree.find(key) == outDegree.end()) outDegree[key] = 0;
            pq.push(stone);
        }
        while (!pq.empty()) {
            vector<int> curr = pq.top();
            if (outDegree[getStoneKey(curr)] == 0) break;
            else {
                result++;
                pq.pop();
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> stones = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 2},
        {2, 1},
        {2, 2},
    };
    int result = s.removeStones(stones);
    return 0;
}
