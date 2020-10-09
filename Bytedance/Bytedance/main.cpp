//
//  main.cpp
//  Bytedance
//
//  Created by chx on 2020/6/23.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int jumpStairs(int N) {
    vector<int> dp(N+1, 0);
    for (int i = 1; i < N+1; ++i) {
        if (i-1 >= 0) dp[i] += 1 + dp[i-1];
        if (i-2 >= 0) dp[i] += 1 + dp[i-2];
        if (i-3 >= 0) dp[i] += 1 + dp[i-3];
    }
    return dp[N];
}

int main(int argc, const char * argv[]) {
    int N = 100;
    cout << jumpStairs(N) << endl;
    return 0;
}
