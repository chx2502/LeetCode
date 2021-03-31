//
//  main.cpp
//  LeetCode_1052
//
//  Created by chx on 2021/2/23.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int left = 0;
        int right = left + X - 1;
        int result = -1;
        
        int origin = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 0) origin += customers[i];
        }
        
        while (right < customers.size()) {
            int curr = origin;
            for (int i = left; i <= right; i++) {
                if (grumpy[i] == 1) curr += customers[i];
            }
            result = max(result, curr);
            left++;
            right++;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int X = 3;
    int result = s.maxSatisfied(customers, grumpy, X);
    return 0;
}
