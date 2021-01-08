//
//  main.cpp
//  LeetCode_454
//
//  Created by chx on 2020/11/27.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int size = (int)A.size();
        if (size == 0) return 0;
        unordered_map<int, int> memory;
        int result = 0;
        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                memory[A[i]+B[j]]++;
            }
        }
        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int temp = C[i] + D[j];
                if (memory.find(-temp) != memory.end()) {
                    result += memory[-temp];
                }
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    vector<int> A = {0};
    vector<int> B = {0};
    vector<int> C = {0};
    vector<int> D = {0};
    int result = s.fourSumCount(A, B, C, D);
    return 0;
}
