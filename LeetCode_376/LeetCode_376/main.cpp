//
//  main.cpp
//  LeetCode_376
//
//  Created by chx on 2020/12/12.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = (int)nums.size();
        if (size < 2) return size;
        
        int ascend, descend;
        ascend = descend = 1;
        for (int i = 1; i < size; i++) {
            if (nums[i] > nums[i-1]) ascend = descend + 1;
            if (nums[i] < nums[i-1]) descend = ascend + 1;
        }
        return max(ascend, descend);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
