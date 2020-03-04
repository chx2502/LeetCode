//
//  main.cpp
//  LeetCode_10.01_合并排序的数组
//
//  Created by chx on 2020/3/3.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        vector<int> temp;
        int i, j;
        i = j = 0;
        while (i < m && j < n) {
            int x = A[i] < B[j] ? A[i++] : B[j++];
            temp.push_back(x);
        }
        while (i < m) temp.push_back(A[i++]);
        while (j < n) temp.push_back(B[j++]);
        A = temp;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
