//
//  main.cpp
//  LeetCode_495
//
//  Created by chx on 2020/10/23.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int size = (int)timeSeries.size();
        if (size == 0) return 0;
        
        int result = 0;
        int endTime = 0;
        for (int i = 0; i < size; i++) {
            int start = timeSeries[i];
            int end = start + duration;
            if (start >= endTime) {
                result += duration;
                endTime = end;
            } else {
                int temp = end - endTime;
                if (temp > 0) result += temp;
                endTime = end;
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> timeSeries = {1, 4};
    int duration = 2;
    int result = s.findPoisonedDuration(timeSeries, duration);
    return 0;
}
