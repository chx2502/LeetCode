//
//  main.cpp
//  LeetCode_925
//
//  Created by chx on 2020/10/21.
//

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (typed.length() < name.length()) return false;
        if (name.compare(typed) == 0) return true;
        int p, q;
        p = q = 0;
        unordered_set<char> charSet;
        if (name[p] != typed[q]) return false;
        while (p < name.length() && q < typed.length()) {
            if (name[p] == typed[q]) {
                charSet.insert(name[p]);
                p++;
                q++;
            } else {
                if (typed[q] != typed[q-1]) return false;
                q++;
            }
        }
        if (p < name.length()) return false;
        while (q < typed.length()) {
            if (typed[q] != typed[q-1]) return false;
            q++;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    string name = "alex";
    string typed = "alexxr";
    Solution s;
    bool result = s.isLongPressedName(name, typed);
    return 0;
}
