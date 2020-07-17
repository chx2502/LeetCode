//
//  main.cpp
//  LeetCode_122
//
//  Created by chx on 2020/7/17.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = (int)prices.size();
        vector<int> dp(size, 0);
        
        int result = 0;
        for (int i = 1; i < size; ++i) dp[i] = prices[i] - prices[i-1];
        for (auto profit : dp) result += profit > 0 ? profit : 0;
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
