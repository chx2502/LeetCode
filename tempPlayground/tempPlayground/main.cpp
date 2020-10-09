//
//  main.cpp
//  tempPlayground
//
//  Created by chx on 2020/5/10.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    int minStep(int root, vector<bool>& visited, vector<bool>& hasApple, int& count, int target) {
        if (root >= visited.size()) return 0;
        if (count == target) return 0;
        int result = 0;
        visited[root] = true;
        if (hasApple[root]) count += 1;
        
        int leftCount, rightCount, leftRoot, rightRoot;
        leftCount = rightCount = 0;
        leftRoot = root*2;
        rightRoot = leftRoot + 1;
        int leftSteps = 2 + minStep(leftRoot, visited, hasApple, leftCount, target);
        int rightSteps = 2 + minStep(rightRoot, visited, hasApple, rightCount, target);
        if (leftCount) result += leftSteps;
        if (rightCount) result += rightSteps;
        count += leftCount + rightCount;

        return result;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<bool> visited(n, false);
        int target = 0;
        for (auto status : hasApple)
            if (status == true) ++target;

        int count = 0;
        return minStep(0, visited, hasApple, count, target);
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 4},
        {1, 5}, {2, 3}, {2, 6},
    };
    vector<bool> hasApple = {false, false, true, false, false, true, false};
    int result = s.minTime(7, edges, hasApple);
    return 0;
}
