//
//  main.cpp
//  LeetCode_887_鸡蛋掉落
//
//  Created by chx on 2020/4/11.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<int> dp(N+1, 0);
        for (int i = 0; i <= N; ++i)
            dp[i] = i;
        
        for (int j = 2; j <= K; ++j) {
            vector<int> dp2(N+1, 0);
            int x = 1;
            dp2[0] = 0;
            for (int n = 1; n <= N; ++n) {
                while (x < n && max(dp[x-1], dp2[n-x]) >= max(dp[x], dp2[n-x-1]))
                    x++;
                dp2[n] = 1 + max(dp[x-1], dp2[n-x]);
            }
            for (int n = 1; n <= N; ++n)
                dp[n] = dp2[n];
        }
        return dp[N];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
