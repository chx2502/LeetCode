#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void swap(vector<int>& array, int a, int b) {
        int temp = array[a];
        array[a] = array[b];
        array[b] = temp;
    }
    void backtracking(vector<int> curr, int first, int size, vector<vector<int>>& result) {
        if (first == size) {
            result.push_back(vector<int>(curr));
            return;
        }
        for (int i = first; i < size; ++i) {
            swap(curr, first, i);
            backtracking(curr, first+1, size, result);
            swap(curr, first, i);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int size = (int)nums.size();
        vector<vector<int>> result;
        if (size == 0) return result;
        backtracking(nums, 0, size, result);
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = s.permute(nums);
    return 0;
}
