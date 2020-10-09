//
//  main.cpp
//  LeeCode_332
//
//  Created by chx on 2020/8/27.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int getHashValue(vector<string>& schedule, int base, int mod) {
        int hashValue = 0;
        for (int i = 0; i < schedule.size(); i++) {
            for (auto &c : schedule[i]) {
                hashValue = 1LL * hashValue * base % mod + c;
                hashValue %= mod;
            }
        }
        return hashValue;
    }
    
    struct cmp {
        bool operator()(const vector<string>& a, const vector<string>& b) {
            if (a[0].compare("JFK") == 0 && b[0].compare("JFK") != 0) return true;
            if (a[0].compare("JFK") != 0 && b[0].compare("JFK") == 0) return false;
            if (a[0].compare(b[0]) == 0) {
                return a[1].compare(b[1]) < 0;
            } else return a[0].compare(b[0]) < 0;
        }
    };
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int size = (int)tickets.size();
        if (size == 0) return {};
        if (size == 1) return tickets[0];
        
        sort(tickets.begin(), tickets.end(), cmp());
        unordered_map<string, vector<int>> M;
        vector<bool> used(size, false);
        for (int i = 0; i < size; i++) {
            string from = tickets[i][0];
            M[from].push_back(i);
        }
        vector<string> result;
        queue<int> Q;
        Q.push(0);
        while (!Q.empty()) {
            int curr = Q.front();
            Q.pop();
            used[curr] = true;
            result.push_back(tickets[curr][0]);
            vector<int> next = M[tickets[curr][1]];
            for (auto &num : next) {
                if (used[num]) continue;
                else {
                    Q.push(num);
                    break;
                }
            }
            if (Q.empty()) {
                bool flag = false;
                for (int i = 1; i < size; i++) {
                    if (tickets[i][0] == "JFK" && !used[i]) {
                        Q.push(i);
                        flag = true;
                        break;
                    }
                }
                if (!flag) result.push_back(tickets[curr][1]);
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<string>> tickets = {
        {"JFK", "SFO"},
        {"JFK", "ATL"},
        {"SFO", "ATL"},
        {"ATL", "JFK"},
        {"ATL", "SFO"}
    };
    vector<string> result = s.findItinerary(tickets);
    return 0;
}
