//
//  main.cpp
//  LeetCode_274
//
//  Created by chx on 2020/10/20.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = (int)citations.size();
        if (size == 0) return 0;
        
        sort(citations.begin(), citations.end());
        
        int result = 0;
        for (int i = size-1; i >= 0; i--) {
            if (size-i <= citations[i])
                result = min(size-i, citations[i]);
            else break;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> citations = {3,0,6,1,5};
    int result = s.hIndex(citations);
    return 0;
}
