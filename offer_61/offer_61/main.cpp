//
//  main.cpp
//  offer_61
//
//  Created by chx on 2021/4/12.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int size = (int)nums.size();
        sort(nums.begin(), nums.end());
        int zeroCount = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] == 0) {
                zeroCount++;
                continue;
            }
            if (i > 0 && nums[i] == nums[i-1]) return false;
        }
        return nums[size-1] - nums[zeroCount] < 5;
        
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
