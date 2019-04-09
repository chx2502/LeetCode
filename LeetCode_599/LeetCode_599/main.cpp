//
//  main.cpp
//  LeetCode_599
//
//  Created by 成鑫 on 2019/1/7.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, unsigned> dict;
        unsigned index_sum = 1999;
        vector<vector<string>> ret(1999);
        for (auto i = list1.cbegin(); i != list1.cend(); ++i) {
            string name = *i;
            unsigned index = unsigned(i - list1.cbegin());
            dict.insert({name, index});
        }
        for (auto i = list2.cbegin(); i != list2.cend(); ++i) {
            string name = *i;
            unsigned index = unsigned(i - list2.begin());
            auto search = dict.find(name);
            if (search != dict.end()) {
                unsigned temp = search->second + index;
                if (temp <= index_sum) {
                    index_sum = temp;
                    ret[index_sum].push_back(name);
                }
            }
        }
        return ret[index_sum];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
