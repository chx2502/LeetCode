#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        unsigned long length = s.length();
        stack<int> numStk;
        stack<string> strStk;
        int num = 0;
        string result = "";
        for (auto &c : s) {
            if (isdigit(c)) num = num * 10 + (c-'0');
            if (isalpha(c)) result.push_back(c);
            if (c == '[') {
                cout << "num = " << num << endl;
                cout << "result = " << result << endl;
                numStk.push(num);
                strStk.push(result);
                num = 0;
                result = "";
            }
            if (c == ']') {
                string base = "";
                int n = numStk.top();
                numStk.pop();
                for (int i = 0; i < n; i++) base.append(result);
                result = strStk.top() + base;
                strStk.pop();
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    string ss = "3[a2[c]]";
    string result = s.decodeString(ss);
    cout << result << endl;
}