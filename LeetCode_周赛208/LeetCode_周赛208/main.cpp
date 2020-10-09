//
//  main.cpp
//  LeetCode_周赛208
//
//  Created by chx on 2020/9/27.
//

#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <deque>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> stk;
        for (auto &opt : logs) {
            if (opt.compare("../") == 0) {
                if (!stk.empty()) stk.pop();
                continue;
            }
            if (opt.compare("./") == 0) continue;
            else stk.push(opt);
        }
        return (int)stk.size();
    }
    
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        vector<int> acc;
        int total = 0;
        for (int i = 0; i < customers.size(); i++) {
            total += customers[i];
            if (total > 4) {
                acc.push_back(4);
                total -= 4;
                
            } else {
                acc.push_back(total);
                total = 0;
            }
        }
        while (total) {
            if (total > 4) {
                acc.push_back(4);
                total -= 4;
                
            } else {
                acc.push_back(total);
                total = 0;
            }
        }
        for (int i = 1; i < acc.size(); i++) acc[i] += acc[i-1];
        int result = -1;
        int max_profit = INT_MIN;
        for (int i = 1; i <= acc.size(); i++) {
            int profit = acc[i-1] * boardingCost - i * runningCost;
            if (profit > 0) {
                if (max_profit < profit) {
                    result = i;
                    max_profit = profit;
                }
            }
        }
        return result;
    }
    
   
};

class ThroneInheritance {
public:
    struct royalMember {
        string name;
        vector<royalMember*> children;
        royalMember(string _name): name(_name) {};
    };
    
    unordered_map<string, bool> death_note;
    unordered_map<string, royalMember*> royalNameList;

    royalMember *root;
    
    ThroneInheritance(string kingName) {
        root = new royalMember(kingName);
        royalNameList[kingName] = root;
        death_note[kingName] = false;
    }
    
    void birth(string parentName, string childName) {
        royalMember *child = new royalMember(childName);
        royalNameList[parentName]->children.push_back(child);
        royalNameList[childName] = child;
        death_note[childName] = false;
    }
    
    void death(string name) {
        death_note[name] = true;
    }
    
    void dfs(royalMember* root, vector<string>& result) {
        if (!root) return;
        if (death_note[root->name] == false) {
            result.push_back(root->name);
        }
        for (auto &child : root->children)
            dfs(child, result);
        return;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> result;
        dfs(root, result);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> customers = {10,10,6,4,7};
    int boardingCost = 1;
    int runningCost = 92;
    int res2 = s.minOperationsMaxProfit(customers, boardingCost, runningCost);
    return 0;
}
