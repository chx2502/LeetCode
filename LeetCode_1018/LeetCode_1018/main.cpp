//
//  main.cpp
//  LeetCode_1018
//
//  Created by chx on 2021/1/14.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> result;
        int size = (int)A.size();
        if (size == 0) return result;
        
        int curr = 0;
        for (int i = 0; i < size; i++) {
            curr <<= 1;
            curr += A[i];
            curr %= 10;
            if (curr % 5 == 0) result.push_back(true);
            else result.push_back(false);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
