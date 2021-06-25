#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int guess(int begin, int end) {
        if (begin >= end) return 0;
        int result = INT32_MAX;
        for (int i = (begin+end)/2; i <= end; i++) {
            int curr = i + max(guess(begin, i-1), guess(i+1, end));
            result = min(curr, result);
        }
        return result;
    }

    int getMoneyAmount(int n) {
        return guess(1, n);
    }
};

int main() {
    Solution s;
    int n = 10;
    cout << s.getMoneyAmount(n) << endl;
    return 0;
}