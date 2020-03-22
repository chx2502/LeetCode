#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int size = (int)A.size();
        if (size == 0) return 0;
        int min, max;

        sort(A.begin(), A.end());
        min = -1;
        max = A[size-1];

        int result = 0;
        for (int i = 0; i < size; ++i) {
            if (A[i] <= min) {
                result += min - A[i] + 1;
                min += 1;
            } else min = A[i];
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> A = {3, 2, 1, 2, 1, 7};
    int res = s.minIncrementForUnique(A);
    return 0;
}
