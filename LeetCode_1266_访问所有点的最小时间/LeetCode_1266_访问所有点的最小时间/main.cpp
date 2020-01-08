//
//  main.cpp
//  LeetCode_1266_访问所有点的最小时间
//
//  Created by chx on 2019/12/7.
//  Copyright © 2019 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        const unsigned long length = points.size();
        if (length == 1) return 0;
        int x, y;
        x = 0;
        y = 1;
        int count = 0;
        
        for(int i = 0; i < length-1; ++i) {
            vector<int> start = points[i];
            vector<int> end = points[i+1];
            int x_i = abs(end[x] - start[x]);
            int y_i = abs(end[y] - start[y]);
            while (x_i && y_i) {
                count++;
                x_i--;
                y_i--;
            }
            while (x_i-- > 0) count++;
            while (y_i-- > 0) count++;
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
