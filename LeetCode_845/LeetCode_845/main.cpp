//
//  main.cpp
//  LeetCode_845
//
//  Created by chx on 2020/10/25.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int size = (int)A.size();
        if (size == 0) return 0;
        
        vector<int> left(size, 0);
        vector<int> right(size, 0);
        
        for (int i = 1; i < size; i++) {
            if (A[i] > A[i-1]) left[i] = left[i-1] + 1;
            else left[i] = 0;
        }
        
        for (int i = size-2; i >= 0; i--) {
            if (A[i] > A[i+1]) right[i] = right[i+1] + 1;
            else right[i] = 0;
        }
        
        int result = 0;
        for (int i = 0; i < size; i++) {
            if (left[i] && right[i])
                result = max(result, left[i]+right[i]+1);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
