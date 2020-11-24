//
//  main.cpp
//  LeetCode_448
//
//  Created by chx on 2020/11/24.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = (int)nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == -1) continue;
            int curr = nums[i];
            while (nums[curr-1] != -1) {
                int temp = nums[curr-1];
                nums[curr-1] = -1;
                curr = temp;
            }
        }
        vector<int> result;
        for (int i = 0; i < size; i++) {
            if (nums[i] != -1) result.push_back(i+1);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
