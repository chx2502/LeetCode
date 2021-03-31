//
//  main.cpp
//  LeetCode_Q49
//
//  Created by chx on 2020/12/29.
//

#include <iostream>
#include <vector>

using namespace std;

class Solustion {
public:
    vector<pair<int, int>> arround = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
    
    void backTracking(
                      vector<int>& l,
                      vector<int>& w,
                      pair<int, int> curr,
                      pair<int, int>& end,
                      int& stepCount,
                      int& result
                      )
    {
        if (curr == end) {
            result = max(result, stepCount);
            return;
        }
        for (pair<int, int> d : arround) {
            pair<int, int> next = { curr.first + d.first, curr.second + d.second };
            if (
                next.first < 0 ||
                next.first > w.size()-1 ||
                next.second < 0 ||
                next.second > l.size()-1 ||
                l[next.second] == 2 ||
                w[next.first] == 2
                )
                continue;
            stepCount++;
            if (next.first == curr.first) l[next.first]++;
            if (next.second == curr.second) w[next.second]++;
            backTracking(l, w, next, end, stepCount, result);
            if (next.first == curr.first) l[next.first]--;
            if (next.second == curr.second) w[next.second]--;
            stepCount--;
        }
    }
    
    int maxDistance(int length, int width) {
        vector<int> lengthPassbyCount(width+1);
        vector<int> widthPassbyCount(length+1);
        int result = 0;
        int stepCount = 0;
        pair<int, int> end = { length, width };
        backTracking(lengthPassbyCount, widthPassbyCount, { 0, 0}, end, stepCount, result);
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solustion s;
    int result = s.maxDistance(4, 3);
    return 0;
}
