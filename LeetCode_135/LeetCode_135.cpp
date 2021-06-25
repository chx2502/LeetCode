#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        unsigned long size = ratings.size();
        vector<int> left(size, 1);
        vector<int> right(size, 1);

        for (int i = 1; i < size; i++) {
            if (ratings[i] > ratings[i-1]) left[i] = left[i-1] + 1;
        }
        for (int i = size-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) right[i] = right[i-1] + 1;
        }
        int result = 0;
        for (int i = 0; i < size; i++) result += max(left[i], right[i]);

        return result;
    }
};

int main() {
    Solution s;
    vector<int> ratings = {1,2,3,4,0};
    int result = s.candy(ratings);
    cout << result << endl;
    return 0;
}