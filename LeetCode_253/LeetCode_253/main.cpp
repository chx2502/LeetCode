//
//  main.cpp
//  LeetCode_253
//
//  Created by chx on 2020/11/24.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int size = (int)intervals.size();
        if (size == 0) return 0;
        vector<int> start;
        vector<int> end;
        
        for (int i = 0; i < size; i++) {
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int count = 0;
        int p, q;
        p = q = 0;
        while (p < size) {
            if (start[p] >= end[q]) {
                count--;
                q++;
            }
            count++;
            p++;
        }

        return count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
