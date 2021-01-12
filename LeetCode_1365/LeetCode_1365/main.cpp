//
//  main.cpp
//  LeetCode_1365
//
//  Created by chx on 2020/10/26.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int size = (int)nums.size();
        vector<int> result;
        if (size < 2) return result;
        
        unordered_map<int, queue<int>> memory;
        for (int i = 0; i < size; i++)
            memory[nums[i]].push(i);
        
        result.assign(size, 0);
        vector<int> temp(size, 0);
        sort(nums.begin(), nums.end());
        for (int i = 1; i < size; i++) {
            if (nums[i] == nums[i-1]) temp[i] = temp[i-1];
            else temp[i] = i;
        }
        for (int i = 0; i < size; i++) {
            int n = nums[i];
            int index = memory[n].front();
            memory[n].pop();
            result[index] = temp[i];
        }
        cout << &temp << endl;
        cout << &result << endl;
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {3, 4, 1, 3, 5, 4, 3, 2};
    vector<int> result = s.smallerNumbersThanCurrent(nums);
    return 0;
}
