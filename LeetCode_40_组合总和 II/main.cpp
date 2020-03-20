#include <iostream>
#include <vector>
#include <numeric>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    map<int, bool> used;
    void helper(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return;
        for (auto &array : matrix) sort(array.begin(), array.end());
        for (int i = 0; i < matrix.size()-1; ++i) {
            for (int j = i+1; j < matrix.size(); ++j) {
                if (matrix[i].size() != matrix[j].size()) continue;
                bool flag = false;
                int size = matrix[i].size();
                for (int idx = 0; idx < size; idx++) {
                    if (matrix[i][idx] != matrix[j][idx]) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) matrix.erase(matrix.begin() + j--);
            }
        }
    }
    void backtrack(vector<int> curr_arr, vector<int>& candidates, int index, int target, int size) {
        int sum = accumulate(curr_arr.begin(), curr_arr.end(), 0);
        if (sum > target) return;
        if (sum == target) {
            result.push_back(vector<int>(curr_arr));
            return;
        }
        for (int i = index; i < size; ++i) {
            curr_arr.push_back(candidates[i]);
            backtrack(curr_arr, candidates, i+1, target, size);
            curr_arr.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int size = (int)candidates.size();
        if (size == 0) return result;

        vector<int> temp;
        backtrack(temp, candidates, 0, target, size);
        helper(result);
        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
