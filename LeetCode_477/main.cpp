#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, unordered_map<int, int>> memory;
    int hammingDistance(int a, int b) {
        auto it = memory.find(a);
        if (it != memory.end()) {
            auto it2 = it->second.find(b);
            if (it2 != it->second.end()) return it2->second;
        }
        a ^= b;
        int result = 0;
        while (a) {
            if (a&1) result++;
            a >>= 1;
        }
        memory[a][b] = result;
        return result;
    }
public:
    int totalHammingDistance(vector<int>& nums) {
        int size = (int)nums.size();
        int result = 0;
        for (int i = 0; i < size; i++) {
            for (int j = i+1; j < size; j++) {
                result += hammingDistance(nums[i], nums[j]);
            }
        }
        return result;
    }
};