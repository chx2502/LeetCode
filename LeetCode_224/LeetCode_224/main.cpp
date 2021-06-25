//
//  main.cpp
//  LeetCode_224
//
//  Created by chx on 2021/3/10.
//

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<string, int> symbolMap = { {"+", 0}, {"-", 0}, {"*", 1}, {"/", 1}, {"(", -1}, {")", -1} };
    int getOpNumber(stack<int> &stk) {
        int result = INT32_MIN;
        if (!stk.empty()) {
            result = stk.top();
            stk.pop();
        }
        return result;
    }
    /*
    中缀表达式转逆波兰表达式：
        数字直接加到表达式末尾
        遇到运算符 x，栈顶运算符为 top，top 的计算优先级大于等于 x 则 top 出栈加入表达式末尾，否则 x 入栈
        遇到左括号 ( ，入栈
        遇到右括号 )，将所有左括号 ( 前的运算符出栈加入表达式末尾，最后 ( 出栈.
    **/
    vector<string> infixToRPN(string s) {
        vector<string> result;
        stack<string> symbols;
        
        string pre = "";
        for (auto c : s) {
            string curr(1, c);
            if (symbolMap.count(curr)) {
                if (pre.length()) result.push_back(pre);
                else {
                    pre += curr;
                    continue;
                }
                pre.clear();
                if (curr.compare("(") == 0) {
                    symbols.push(curr);
                    continue;
                }
                if (curr.compare(")") == 0) {
                    while (!symbols.empty()) {
                        string top = symbols.top();
                        symbols.pop();
                        if (top.compare("(") != 0) result.push_back(top);
                        else break;
                    }
                    continue;
                }
                while (!symbols.empty() && symbolMap[symbols.top()] >= symbolMap[curr]) {
                    result.push_back(symbols.top());
                    symbols.pop();
                }
                symbols.push(curr);
            } else pre += curr;
        }
        if (pre.length()) result.push_back(pre);
        while (!symbols.empty()) {
            result.push_back(symbols.top());
            symbols.pop();
        }
        return result;
    }
public:
    int calculate(string s) {
        // write code here
        string infix = "";
        for (auto c : s) {
            if (c != ' ') infix.push_back(c);
        }
        vector<string> RPN = infixToRPN(infix);
        stack<int> numbers;
        for (const string op : RPN) {
            if (symbolMap.count(op)) {
                int b = getOpNumber(numbers);
                int a = getOpNumber(numbers);
                if (a != INT32_MIN && b != INT32_MIN) {
                    if (op.compare("+") == 0) numbers.push(a+b);
                    if (op.compare("-") == 0) numbers.push(a-b);
                    if (op.compare("*") == 0) numbers.push(a*b);
                    if (op.compare("/") == 0) numbers.push(a/b);
                    cout << a << op << b << endl;
                }
            } else numbers.push(stoi(op));
        }
        return numbers.top();
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string str = "(1+(4+5+2)-3)+(6+8)";
    int result = s.calculate(str);
    return 0;
}
