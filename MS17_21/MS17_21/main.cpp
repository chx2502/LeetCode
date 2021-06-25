//
//  main.cpp
//  MS17_21
//
//  Created by chx on 2021/4/2.
//

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>stk;
        int water = 0;
        int result = 0;
        for (int i = 0; i < height.size(); i++) {
            int h = height[i];
            if (stk.empty() || h > stk.top()) {
                stk.push(h);
                result += water;
                water = 0;
            } else {
                water += stk.top() - h;
            }
        }

        stack<int> stk2;
        water = 0;
        for (int i = (int)height.size()-1; i >= 0 ; i--) {
            int h = height[i];
            if (stk2.empty() || h >= stk2.top()) {
                stk2.push(h);
                result += water;
                water = 0;
            } else {
                water += stk2.top() - h;
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
