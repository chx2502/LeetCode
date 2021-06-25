#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numWays(int n, int k) {
        if (n == 1) return k;

        int pre, prepre, result;

        prepre = k;
        pre = k*k;
        
        result = pre;
        for (int i = 2; i < n; i++) {
            result = pre * (k-1) + prepre * (k-1);
            prepre = pre;
            pre = result;
        }
        return result;
    }
};

int main() {
    Solution s;
    int n = 7;
    int k = 2;
    int result = s.numWays(n, k);
    cout << result << endl;
}