//
//  main.cpp
//  LeetCode_659
//
//  Created by chx on 2020/12/4.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> listTable;
        for (auto num : nums) {
            if (listTable.find(num) == listTable.end()) {
                listTable[num] = priority_queue<int, vector<int>, greater<int>>();
            }
            if (listTable.find(num-1) != listTable.end()) {
                int prev = listTable[num-1].top();
                listTable[num-1].pop();
                if (listTable[num-1].empty()) {
                    listTable.erase(num-1);
                }
                listTable[num].push(prev+1);
            } else {
                listTable[num].push(1);
            }
        }
        for (auto it = listTable.begin(); it != listTable.end(); it++) {
            priority_queue<int, vector<int>, greater<int>> q = it->second;
            if (q.top() < 3) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
