//
//  main.cpp
//  LeetCode_49
//
//  Created by chx on 2020/12/14.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> dict;
        vector<vector<string>> result;
        int index = 0;
        for (int i = 0; i < strs.size(); i++) {
            string word = strs[i];
            sort(word.begin(), word.end());
            if (dict.find(word) == dict.end()) {
                vector<string> temp;
                temp.push_back(strs.at(i));
                result.push_back(temp);
                dict[word] = index++;
            } else {
                result[dict[word]].push_back(strs.at(i));
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
