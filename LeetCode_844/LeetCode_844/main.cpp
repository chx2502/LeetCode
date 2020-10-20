//
//  main.cpp
//  LeetCode_844
//
//  Created by chx on 2020/10/19.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int lengthS = (int)S.length();
        int lengthT = (int)T.length();
        
        stack<char> stkS;
        stack<char> stkT;
        
        for (int i = 0; i < lengthS; i++) {
            char c = S[i];
            if (c == '#') {
                if (!stkS.empty()) stkS.pop();
            } else stkS.push(c);
        }
        for (int i = 0; i < lengthT; i++) {
            char c = T[i];
            if (c == '#') {
                if (!stkT.empty()) stkT.pop();
            } else stkT.push(c);
        }
        
        if (stkS.size() != stkT.size()) return false;
        
        string SS = "";
        string TT = "";
        while (!stkS.empty()) {
            SS = stkS.top() + SS;
            stkS.pop();
        }
        while (!stkT.empty()) {
            TT = stkT.top() + TT;
            stkT.pop();
        }
        
        return SS.compare(TT) == 0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
