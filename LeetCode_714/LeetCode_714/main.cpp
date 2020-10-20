//
//  main.cpp
//  LeetCode_714
//
//  Created by chx on 2020/10/16.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int size = (int)prices.size();
        if (size < 2) return 0;
        int profit = 0;
        int min = prices[0];
        for (int i = 0; i < size; i++) {
            if (prices[i] < min) min = prices[i];
            else {
                if (prices[i]-fee > min) {
                    profit += prices[i]-fee-min;
                    min = prices[i]-fee;
                }
            }
        }
        return profit;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
