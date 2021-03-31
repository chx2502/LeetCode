//
//  main.cpp
//  LeetCode_842
//
//  Created by chx on 2020/12/8.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        int sum = 0;
        vector<int> result;
        for (int i = 1; i <= S.length(); i++) {
            result.clear();
            int begin = stoi(S.substr(0, i));
            int end = i;
            for (int j = end; j <= S.length(); j++) {
                
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
