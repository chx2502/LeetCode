//
//  main.cpp
//  LeetCode_556
//
//  Created by chx on 2021/2/28.
//

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        long long result = -1;
        
        string s = to_string(n);
        stack<char> stk;
        for (int i = (int)s.length()-1; i >= 0; i--) {
            if (stk.empty() || s[i] >= stk.top()) {
                stk.push(s[i]);
            } else {
                int j = 0;
                while (!stk.empty() && s[i] < stk.top()) {
                    stk.pop();
                    j++;
                }
                swap(s[i], s[i+j]);
                sort(s.begin() + i + 1, s.end());
                result = stoll(s);
                if (result > INT_MAX) return -1;
                else return result;
            }

        }
        
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    int n = 230241;
    Solution s;
    int result = s.nextGreaterElement(n);
    return 0;
}
