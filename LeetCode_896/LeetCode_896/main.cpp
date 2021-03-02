//
//  main.cpp
//  LeetCode_896
//
//  Created by chx on 2021/2/28.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
//    bool isMonotonic(vector<int>& A) {
//        if (A.size() < 3) return true;
//        return is_sorted(A.begin(), A.end()) || is_sorted(A.rbegin(), A.rend());
//    }
    
    bool isMonotonic(vector<int>& A) {
        int size = (int)A.size();
        if (size < 3) return true;
        
        bool isIncrease, isDecrease;
        isIncrease = isDecrease = true;
        for (int i = 1; i < size; i++) {
            if (A[i-1] < A[i]) isDecrease = false;
            if (A[i-1] > A[i]) isIncrease = false;
        }
        return isIncrease || isDecrease;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> A = {11,11,9,4,3,3,3,1,-1,-1,3,3,3,5,5,5};
    Solution s;
    bool result = s.isMonotonic(A);
    return 0;
}
