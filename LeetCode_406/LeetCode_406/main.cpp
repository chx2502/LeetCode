//
//  main.cpp
//  LeetCode_406
//
//  Created by chx on 2020/10/23.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int size = (int)people.size();
        if (size == 0) return people;
        
        auto cmp = [](vector<int> A, vector<int> B) {
            if (A[0] == B[0]) return A[1] < B[1];
            else return A[0] > B[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        vector<vector<int>> result;
        for (auto &array : people) pq.push(array);
        while(!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> people = {
        {7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}
    };
    Solution s;
    vector<vector<int>> result = s.reconstructQueue(people);
    return 0;
}
