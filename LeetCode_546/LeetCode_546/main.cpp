//
//  main.cpp
//  LeetCode_546
//
//  Created by chx on 2020/8/15.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<vector<int>>> dp;
    int calcPoints(int l, int r, int k, vector<int>& boxes) {
        if (l > r) return 0;
        if (dp[l][r][k] != 0) return dp[l][r][k];
        while(r > 2 && boxes[r-2] == boxes[r-1]) {
            r--;
            k++;
        }
        
        dp[l][r][k] = calcPoints(l, r-1, 0, boxes) + (k+1)*(k+1);
        for (int i = l; i < r; i++) {
            if (boxes[i-1] == boxes[r-1]) {
                dp[l][r][k] = max(dp[l][r][k], calcPoints(l, i, k+1, boxes)+calcPoints(i+1, r-1, 0, boxes));
            }
        }
        return dp[l][r][k];
    }
    
    int removeBoxes(vector<int>& boxes) {
        int size = (int)boxes.size();
        dp.assign(size+1, vector<vector<int>>(size+1, vector<int>(size+1, 0)));
        return calcPoints(1, size, 0, boxes);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> boxes = {1, 3, 2, 2, 2, 3, 4, 3, 1};
    int result = s.removeBoxes(boxes);
    return 0;
}
