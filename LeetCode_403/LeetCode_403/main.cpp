//
//  main.cpp
//  LeetCode_403
//
//  Created by chx on 2021/4/29.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    bool result;
    unordered_map<int, int> indexMap;
    unordered_map<int, unordered_map<int, bool>> tried;
public:
    void backTracking(int curr, int k, vector<int>& stones) {
        if (tried[curr][k]) return;
        if (curr == stones.size()-1) {
            result = true;
            return;
        }
        printf("index = %d, k = %d\n", curr, k);
        vector<int> steps = {k-1, k, k+1};
        for (auto step : steps) {
            if (step < 1) continue;
            auto it = indexMap.find(stones[curr] + step);
            if (it == indexMap.end()) continue;
            backTracking(it->second, step, stones);
            if (result) return;
            tried[it->second][step] = true;
        }
    }
    
    bool canCross(vector<int>& stones) {
        unsigned long length = stones.size();
        if (length < 2) return true;
        for (int i = 0; i < length; i++) {
            indexMap[stones[i]] = i;
        }
        backTracking(0, 0, stones);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> stones = {0, 1, 2, 3, 4, 8, 9, 11};
    bool result = s.canCross(stones);
    cout << (result ? "true" : "false") << endl;
    return 0;
}
