//
//  main.cpp
//  LeetCode_674
//
//  Created by chx on 2020/10/10.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int size = (int)nums.size();
        if (size == 0) return 0;
        
        int result = 1;
        int count = 1;
        for (int i = 1; i < size; i++) {
            if (nums[i] > nums[i-1]) count++;
            else {
                result = max(result, count);
                count = 1;
            }
        }
        return max(result, count);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
