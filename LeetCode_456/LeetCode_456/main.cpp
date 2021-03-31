//
//  main.cpp
//  LeetCode_456
//
//  Created by chx on 2021/3/24.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int size = (int)nums.size();
        int min, max, medium;
        min = max = medium = INT_MIN;
        stack<int> stk;
        for (int i = size-1; i >= 0; i--) {
            if (nums[i] < medium) return true;
            while(!stk.empty() && nums[i] > stk.top()) {
                medium = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
