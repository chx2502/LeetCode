//
//  main.cpp
//  LeetCode_973
//
//  Created by chx on 2020/11/9.
//

#include <iostream>
#include <vector>
#include <queue>
#include "math.h"
using namespace std;

class Solution {
public:
    
    double getDistance(vector<int>& point) {
        return sqrt(pow(point[0], 2)+pow(point[1], 2));
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto cmp = [&](vector<int>& a, vector<int>& b) { return getDistance(a) < getDistance(b); };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (auto &point : points) {
            pq.push(point);
        }
        vector<vector<int>> result;
        for (int i = 0; i < K; i++) {
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
