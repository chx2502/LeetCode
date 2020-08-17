//
//  main.cpp
//  LeetCode_733
//
//  Created by chx on 2020/8/16.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> around = {
        {-1, 0},
        {0, -1},
        {1, 0},
        {0, 1}
    };
    void contagion(vector<vector<int>>& image, int row, int col, int newColor, int target) {
        if (row < 0 || col < 0 || row >= image.size() || col >= image[0].size()) return;
        if (image[row][col] != target) return;
        image[row][col] = newColor;
        for (auto &next : around)
            contagion(image, row+next.first, col+next.second, newColor, target);
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        contagion(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> image = {
        {0, 0, 0},
        {1, 0, 0},
//        {1, 0, 1}
    };
    vector<vector<int>> res = s.floodFill(image, 1, 0, 2);
    return 0;
}
