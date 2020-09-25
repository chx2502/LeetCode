//
//  main.cpp
//  LeetCode_189
//
//  Created by chx on 2020/9/25.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> isMove;
    void move(int posA, int posB, vector<int>& nums, int size, int k) {
        isMove[posA] = true;
        if (!isMove[posB]) {
            move(posB, (posB + k) % size, nums, size, k);
            swap(nums[posA], nums[posB]);
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int size = (int)nums.size();
        isMove.assign(size, false);
        for (int i = 0; i < size; i++) {
            if (isMove[i]) continue;
            move(i, (i+k) % size, nums, size, k);
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {-1,-100,3,99};
    Solution s;
    s.rotate(nums, 2);
    return 0;
}
