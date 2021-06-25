//
//  main.cpp
//  offer_60
//
//  Created by chx on 2021/4/12.
//

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, unordered_map<int, double>> memory;
    double probabilityOfX(int n, int X) {
        auto it = memory.find(n);
        if (it != memory.end()) {
            auto iit = it->second.find(X);
            if (iit != it->second.end()) return iit->second;
        }
        
        if (X < n*1 || X > n*6) return 0.0;
        if (n == 1) return 1.0/6;
        double result = 0.0;
        for (int i = 1; i < X; i++) {
            result += probabilityOfX(1, i) * probabilityOfX(n-1, X-i);
        }
        memory[n][X] = result;
        return result;
    }
    
    vector<double> dicesProbability(int n) {
        if (n == 0) return {};
        vector<double> result;
        priority_queue<double, vector<double>, greater<double>> pq;
        for (int x = n; x <= n*6; x++)
            result.push_back(probabilityOfX(n, x));
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    double res1 = s.probabilityOfX(1, 6);
    double res2 = s.probabilityOfX(2, 2);
    double res3 = s.probabilityOfX(2, 3);
    vector<double> res4 = s.dicesProbability(2);
    return 0;
}
