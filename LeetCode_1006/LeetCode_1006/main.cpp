//
//  main.cpp
//  LeetCode_1006
//
//  Created by chx on 2021/4/2.
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int clumsy(int N) {
        stack<int> stk;
        int index = 0;
        stk.push(N--);
        while (N) {
            if (index % 4 == 0) stk.top() *= N;
            else if (index % 4 == 1) stk.top() /= N;
            else if (index % 4 == 3) stk.push(-N);
            else stk.push(N);
        }
        index++;
        N--;
        int result = 0;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
