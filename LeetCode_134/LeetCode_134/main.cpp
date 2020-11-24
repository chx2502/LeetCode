//
//  main.cpp
//  LeetCode_134
//
//  Created by chx on 2020/11/18.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool flag;
public:
    bool loop(int start, int x, int curr, vector<int>& gas, vector<int>& cost) {
        if (x == start && flag) return true;
        int size = (int)gas.size();
        flag = true;
        curr = curr + gas[x] - cost[x];
        if (curr < 0) return false;
        else return loop(start, (x+1)%size, curr, gas, cost);
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = (int)gas.size();
        for (int i = 0; i < size; i++) {
            flag = false;
            if (loop(i, i, 0, gas, cost)) return i;
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    int result = s.canCompleteCircuit(gas, cost);
    return 0;
}
