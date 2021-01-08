//
//  main.cpp
//  LeetCode_860
//
//  Created by chx on 2020/12/10.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> exchange;
        for (int &money : bills) {
            if (money == 5) exchange[5]++;
            if (money == 10) {
                exchange[5]--;
                exchange[10]++;
            }
            if (money == 20) {
                if (exchange[10] > 0) {
                    exchange[10]--;
                    exchange[5]--;
                } else {
                    exchange[5] -= 3;
                }
            }
            if (exchange[5] < 0 || exchange[10] < 0) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
