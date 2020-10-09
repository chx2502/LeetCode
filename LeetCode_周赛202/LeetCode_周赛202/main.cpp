//
//  main.cpp
//  LeetCode_周赛202
//
//  Created by chx on 2020/8/16.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int size = (int)arr.size();
        int i, j, k;
        i = 0;
        j = 1;
        k = 2;
        while (k < size) {
            if (arr[i]&1 && arr[j]&1 && arr[k]&1) return true;
            else {
                i += 1;
                j += 1;
                k += 1;
            }
        }
        return false;
    }
    
    int minOperations(int n) {
        if (n < 2) return 0;
        int result = 0;
        for (int i = 0; i < n/2; i++) {
            result += n - (2*i+1);
        }
        return result;
    }
    
//    vector<bool> isSelected;
//    unordered_map<int, int> index_map;
//    // position 中的点进行 m 次切分，取最长的一段
//    vector<vector<int>> createDistArray(vector<int>& selected, vector<int>& position) {
//        vector<vector<int>> result;
//        for (auto num : selected) {
//            vector<int> dist;
//            for (int i = 0; i < position.size(); i++) {
//                if (isSelected[i]) continue;
//                dist.push_back(abs(position[i]-num));
//            }
//            result.push_back(dist);
//        }
//        return result;
//    }
//
//    int maxDistance(vector<int>& position, int m) {
//        int size = (int)position.size();
//        sort(position.begin(), position.end(), less<int>());
//        for (int i = 0; i < size; i++) index_map[position[i]] = i;
//        if (m == 2) return position[size-1] - position[0];
//        if (m > size) return 0;
//
//        vector<int> selected = { position[0], position[size-1] };
//        isSelected.assign(size, false);
//        isSelected[0] = isSelected.back() = true;
//        int result = 0;
//        while(m-2) {
//            vector<vector<int>> distArray = createDistArray(selected, position);
//            int select = 0x3f3f3f3f;
//            for (int i = 0; i < distArray[0].size(); i++) {
//                for (auto &array : distArray) {
//                    selected = min
//                }
//            }
//        }
//
//        return result;
//    }
    
    unordered_map<int, int> memory;
    int minDays(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (memory.find(n) != memory.end()) return memory[n];
        
        memory[n] = min(minDays(n/3)+n%3+1, minDays(n/2)+n%2+1);
        
        return memory[n];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
//    vector<int> position = {1, 2, 3, 4, 5, 8, 12, 19};
//    int res3 = s.maxDistance(position, 3);
    vector<int> test = {10 ,6, 1, 56, 540, 820592};
    for (auto n : test) cout << s.minDays(n) << " ";
    cout << endl;
//    int res4 = s.minDays(1);
    return 0;
}
