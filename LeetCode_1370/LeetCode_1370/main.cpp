//
//  main.cpp
//  LeetCode_1370
//
//  Created by chx on 2020/11/25.
//

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void stage1(vector<char>& charArray, unordered_map<char, int>& charMap, string& result) {
        for (auto c : charArray) {
            if (charMap[c] > 0) {
                result.push_back(c);
                charMap[c]--;
            }
        }
    }
    void stage2(vector<char>& charArray, unordered_map<char, int>& charMap, string& result) {
        int size = (int)charArray.size();
        for (int i = size-1; i >= 0; i--) {
            char c = charArray[i];
            if (charMap[c] > 0) {
                result.push_back(c);
                charMap[c]--;
            }
        }
    }
    string sortString(string s) {
        string result = "";
        int length = (int)s.length();
        if (length == 0) return result;
        
        unordered_map<char, int> charMap;
        vector<char> charArray;
        for (auto c : s) {
            if (charMap.find(c) == charMap.end()) charArray.push_back(c);
            charMap[c]++;
        }
        sort(charArray.begin(), charArray.end());
        
        while(result.length() < length) {
            stage1(charArray, charMap, result);
            stage2(charArray, charMap, result);
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
