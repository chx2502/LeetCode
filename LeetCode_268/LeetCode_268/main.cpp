//
//  main.cpp
//  LeetCode_268
//
//  Created by chx on 2020/9/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int acc(int N) {
        return (N-1) * N / 2;
    }
    
//    int missingNumber(vector<int>& nums) {
//        int size = (int)nums.size();
//        if (size == 0) return -1;
//
//        return acc(size+1) - accumulate(nums.begin(), nums.end(), 0);
//    }
    
    int missingNumber(vector<int>& nums) {
        int size = (int)nums.size();
        int result = size;
        for (int i = 0; i < size; i++) result ^= i^nums[i];
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << (9^6^4^2^3^5^7^0^1) << std::endl;
    return 0;
}
