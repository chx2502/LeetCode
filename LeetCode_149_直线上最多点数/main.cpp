#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {   
public:
    int maxPoints(vector<vector<int>>& points) {
        int size = (int)points.size();

        int result = 1;
        for (int i = 0; i < size; i++) {
            unordered_map<string, int> memo;
            int count = 0;
            for (int j = i+1; j < size; j++) {
                int x1, x2, y1, y2;
                x1 = points[i][0];
                y1 = points[i][1];
                x2 = points[j][0];
                y2 = points[j][1];
                int k = gcd(x1-x2, y1-y2);
                string s = to_string((x1-x2)/k) + "_" + to_string((y1-y2)/k);
                memo[s]++;
                count = max(count, memo[s]);
            }
            result = max(result, count+1);
        }
        return result;
    }
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a%b);
    }
};
