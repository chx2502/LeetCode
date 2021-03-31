//
//  main.cpp
//  LeetCode_240_搜索二维矩阵 II
//
//  Created by 成鑫 on 2019/4/2.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool bSearch(vector<int>& array, int left, int right, int target) {
        if (left > right) return false;
        if (left == right) return array[left] == target;
        int mid = (left+right) / 2;
        if(array[mid] == target)
            return true;
        else if (array[mid] > target)
            return bSearch(array, left, mid-1, target);
        else return bSearch(array, mid+1, right, target);
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)
            return false;
        if (matrix[0].size() == 0)
            return false;
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        while(m >= 0 && n >= 0 && matrix[--m][--n] > target) {
            if (m < 0) {
                n += 1;
                return bSearch(matrix[0], 0, (int)matrix[0].size()-1, target);
            }
            if (n < 0) {
                m += 1;
                for (int i = 0; i < m; i++)
                    if (matrix[i][0] == target)
                        return true;
                return false;
            }
        }
        if (matrix[m][n] == target)
            return true;
        else {
            for (int i = 0; i <= m; i++)
                for (int j = 0; j <=n; j++)
                    if (matrix[i][j] == target)
                        return true;
            return false;
        }
    }
    
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int m = (int)matrix.size();
        if (m == 0) return false;
        int n = (int)matrix[0].size();
        
        int x = 0;
        int y = n-1;
        while (x >= 0 && y >= 0 && x < m && y < n) {
            if (matrix[x][y] == target) return true;
            if (matrix[x][y] > target) {
                y--;
            } else {
                x++;
            }
        }
        return false;
    }
    
    
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> blank = {{-5}};
    vector<vector<int>> matrix = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    Solution solution;
    bool result = solution.searchMatrix(blank, -10);
    return 0;
}
