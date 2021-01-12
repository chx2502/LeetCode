//
//  main.cpp
//  LeetCode_941
//
//  Created by chx on 2020/11/3.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int size = (int)A.size();
        if (size < 3) return false;
        int i = 0;
        while (i < size-1 && A[i] < A[i+1]) i++;
        if (i == 0 || i == size-1) return false;
        while (i < size-1 && A[i] > A[i+1]) i++;
        
        return i == size-1;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> A = {0,1,2,3,4,8,9,10,11,12};
    Solution s;
    bool result = s.validMountainArray(A);
    return 0;
}
