//
//  main.cpp
//  LeetCode_56_合并区间
//
//  Created by chx on 2020/4/16.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    const int min = 0;
    const int max = 1;
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        
        map<int, vector<vector<int>>, less<int>> section_map;
        map<int, int, less<int>> range_map;
        
        for (auto &section : intervals) {
            const int start = section[min];
            const int end = section[max];
            section_map[start].push_back(section);
            if (range_map.find(start) == range_map.end())
                range_map[start] = end;
            else range_map[start] = range_map[start] < end ? end : range_map[start];
        }
        
        vector<vector<int>> pool;
        
        for (auto &element : section_map) {
            int end = -1;
            vector<int> select;
            for (auto &section : element.second) {
                if (end < section[max]) {
                    end = section[max];
                    select = section;
                }
            }
            pool.push_back(select);
        }
        int size = (int)pool.size();
        for (int i = 0; i < size; ++i) {
            int begin = pool[i][min];
            int end = pool[i][max];
            int next = i;
            for (int j = 1; j < size; ++j) {
                if (pool[j][min] > end) break;
                if (end <= pool[j][max]) {
                    end = pool[j][max];
                }
                next = j;
            }
            i = next;
            result.push_back({begin, end});
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> intervals = {
        {1, 4},
        {2, 3},
    };
    vector<vector<int>> result = s.merge(intervals);
    return 0;
}
