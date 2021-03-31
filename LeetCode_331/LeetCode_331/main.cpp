//
//  main.cpp
//  LeetCode_331
//
//  Created by chx on 2021/3/12.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    
    pair<char, char> pop3(stack<char>& stk, char first, char second) {
        stk.pop();
        stk.pop();
        if (stk.empty()) return {'#', '#'};
        stk.pop();
        if (stk.empty()) return {',', ','};
        second = stk.top();
        stk.push('#');
        first = stk.top();
        return pair<char, char>(first, second);
    }
    
    bool isValidSerialization(string preorder) {
        int length = (int)preorder.length();
        if (length == 0) return false;
        if (length ==1 && preorder[0] == '#') return true;
        
        char first, second;
        first = preorder[0];
        second = ',';
        stack<char> stk;
        stk.push(preorder[0]);
        
        for (int i = 1; i < length; i++) {
            if (first == ',' && second == ',') return false;
            char curr = preorder[i];
            if (curr == ',') continue;
            stk.push(curr);
            second = first;
            first = curr;
            while (first == second && first == '#') {
                pair<char, char> temp = pop3(stk, first, second);
                first = temp.first;
                second = temp.second;
            }
        }
        if (stk.empty() || (first == ',' && second == ',')) return true;
        return false;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    string preorder = "#,#";
    bool result = s.isValidSerialization(preorder);
    return 0;
}
