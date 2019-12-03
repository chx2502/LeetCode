//
//  main.cpp
//  LeetCode_771_宝石与石头
//
//  Created by chx on 2019/11/7.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> jewel_set;
        for (char c : J)
            jewel_set.insert(c);
        int ret = 0;
        for (char c : S)
            if (jewel_set.find(c) != jewel_set.end())
                ret++;

        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
