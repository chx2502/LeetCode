//
//  main.cpp
//  LeetCode_503
//
//  Created by chx on 2021/2/28.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        int size = (int)nums.size();

        vector<int> result(size);
        for (int i = 2*size-1; i >= 0; i--) {
            while (!stk.empty() && nums[i%size] >= stk.top()) stk.pop();
            if (stk.empty()) result[i%size] = -1;
            else result[i%size] = stk.top();
            stk.push(nums[i]);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
