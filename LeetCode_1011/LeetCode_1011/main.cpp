//
//  main.cpp
//  LeetCode_1011
//
//  Created by chx on 2021/4/26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        unsigned long size = weights.size();
        
        int floor, ceil;
        floor = weights.back();
        if (D == size) return floor;
        
        vector<int> preSum(size+1, 0);

        for (int i = 1; i <= size; i++) {
            preSum[i] = preSum[i-1] + weights[i-1];
        }
        ceil = preSum[size-D];
        
        for (int capacity = floor; capacity <= ceil; capacity++) {
            cout << "capacity = " << capacity << endl;
            unsigned long i, j;
            i = j = 0;
            int count = 0;
            while (count < D && i <= size) {
                j = i+1;
                while (j <= size && preSum[j] - preSum[i] <= capacity) j++;
                printf("trans[%d][%d]\n", i, j);
                i = j;
                count++;
            }
            if (i >= size) return capacity;
        }
        return ceil;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int D = 5;
    Solution s;
    int result = s.shipWithinDays(weights, D);
    return 0;
}
