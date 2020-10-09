//
//  main.cpp
//  LeetCode_秋季赛
//
//  Created by chx on 2020/9/12.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int mod = 1e9+7;
    int bSearch(vector<int>& array, int begin, int end, int n) {
        if (begin > end) {
            if (array[end] > n) return end-1;
            if (array[end] < n) return end;
        }
        int mid = begin + (end-begin)/2;
        if (array[mid] == n) return mid;
        if (array[mid] > n) return bSearch(array, begin, mid-1, n);
        else return bSearch(array, mid+1, end, n);
    }
    
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        int result = 0;
        for (int i = 0; i < staple.size(); i++) {
            int s = staple[i];
            if (s >= x) break;
            int count = bSearch(drinks, 0, (int)drinks.size()-1, x-s)+1;
            result %= mod;
            result += count;
        }
        return result % mod;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    vector<int> staple = {2, 1, 1};
    vector<int> drinks = {8, 9, 5, 1};
    int res1 = s.breakfastNumber(staple, drinks, 9);
    return 0;
}
