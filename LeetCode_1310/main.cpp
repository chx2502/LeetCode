#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        unsigned long size = arr.size();
        vector<int> memory(arr.begin(), arr.end());
        for (int i = 1; i < size; i++) {
            memory[i] ^= memory[i-1];
        }

        vector<int> result;
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            int ans = memory[r];

            if (l > 0) ans ^= memory[l-1];

            result.push_back(ans);
        }
        return result;
    }
};