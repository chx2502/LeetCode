//
//  main.cpp
//  LeetCode_1423
//
//  Created by chx on 2021/4/1.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = (int)cardPoints.size();
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if (n == k) return total;
        int len = n-k;
        int curr = accumulate(cardPoints.begin(), cardPoints.begin()+len, 0);
        int exclude = curr;
        for (int i = len; i < n; i++) {
            curr = curr + cardPoints[i] - cardPoints[i+len];
            exclude = min(exclude, curr);
        }
        
        return total - exclude;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3;
    Solution s;
    int result = s.maxScore(cardPoints, k);
    return 0;
}
