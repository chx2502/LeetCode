//
//  main.cpp
//  LeetCode_周赛185
//
//  Created by chx on 2020/4/19.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    string reformat(string s) {
        string s1 = "";
        string s2 = "";
        string result = "";
        for (auto &c : s) {
            if (c >= '0' && c <= '9') s1.push_back(c);
            else s2.push_back(c);
        }
        int l1, l2;
        l1 = (int)s1.length();
        l2 = (int)s2.length();
        if (abs(l1-l2) >= 2) return result;
        if (l1 < l2) {
            swap(s1, s2);
            swap(l1, l2);
        }
        bool flag = true;
        int i, j;
        i = j = 0;
        while (i < l1 || j < l2) {
            if (flag) {
                result.push_back(s1[i++]);
                flag = false;
            } else {
                result.push_back(s2[j++]);
                flag = true;
            }
        }
        return result;
    }
    
//    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
//        map<int, map<string, int, greater<string>>, greater<int>> order_map;
//        set<string, greater<string>> food;
//        set<int, greater<int>> tableSet;
//        for (auto &order : orders) {
//            int table = stoi(order[1]);
//            string foodName = order[2];
//            if (order_map.find(table) == order_map.end())
//                order_map[table][foodName] = 1;
//            else order_map[table][foodName] += 1;
//            order_map[table]["table"] = table;
//            food.insert(foodName);
//            tableSet.insert(table);
//        }
//        vector<vector<string>> result;
//        vector<string> r1 = {"table"};
//        result.push_back(r1);
//        for (auto &foodName : food) {
//            result[0].push_back(foodName);
//        }
//        int col = (int)result[0].size();
//        int tableNum = (int)order_map.size();
//        for (auto &table : tableSet) {
//            vector<string> temp;
//            map<string, int, greater<string>> order = order_map[table];
//            for (auto &str : result[0]) {
//                temp.push_back();
//            }
//        }
//    }
    
};

int main(int argc, const char * argv[]) {
    Solution s;
    string str = "covid2019";
    string result = s.reformat(str);
    return 0;
}
