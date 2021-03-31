//
//  main.cpp
//  LeetCode_1207
//
//  Created by chx on 2020/10/28.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<bool> memory(2001, false);
        unordered_map<int, int> M;
        for (auto num : arr) {
            M[num]++;
        }
        for (auto item : M) {
            int times = item.second;
            if (!memory[times]) memory[times] = true;
            else return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
