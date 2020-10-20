//
//  main.cpp
//  LeetCode_1122
//
//  Created by chx on 2020/10/20.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> order_map;
        for (int i = 0; i < arr2.size(); i++) {
            order_map[arr2[i]] = i;
        }
        
        auto cmp = [&](const int a, const int b) {
            if (order_map.count(a) && order_map.count(b))
                return order_map[a] > order_map[b];
            else {
                if (order_map.count(a)) return false;
                if (order_map.count(b)) return true;
                return a > b;
            }
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (auto num : arr1) pq.push(num);
        
        vector<int> result;
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
