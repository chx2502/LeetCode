#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int length = (int)s.length();
        if (length == 0) return "";

        string result = "";
        for (auto &c : s) {
            if (c == ')') {
                // pop until '('
                string temp = "";
                while (!result.empty()) {
                    char top = result.back();
                    result.pop_back();
                    if (top == '(') break;
                    else temp.push_back(top);   // reverse
                }
                result += temp;
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};
