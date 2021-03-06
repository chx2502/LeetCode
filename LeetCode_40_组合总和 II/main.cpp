#include <iostream>
#include <vector>
#include <numeric>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
//    vector<vector<int>> result;
//    map<int, bool> used;
//    // 将 result 中的数组排序后，去掉重复数组
//    void helper(vector<vector<int>>& matrix) {
//        if (matrix.size() == 0) return;
//        for (auto &array : matrix) sort(array.begin(), array.end());
//        for (int i = 0; i < matrix.size()-1; ++i) {
//            for (int j = i+1; j < matrix.size(); ++j) {
//                if (matrix[i].size() != matrix[j].size()) continue;
//                bool flag = false;
//                int size = matrix[i].size();
//                for (int idx = 0; idx < size; idx++) {
//                    if (matrix[i][idx] != matrix[j][idx]) {
//                        flag = true;
//                        break;
//                    }
//                }
//                if (!flag) matrix.erase(matrix.begin() + j--);
//            }
//        }
//    }
//    void backtrack(vector<int> curr_arr, vector<int>& candidates, int index, int target, int size) {
//        int sum = accumulate(curr_arr.begin(), curr_arr.end(), 0);
//        if (sum > target) return;
//        if (sum == target) {
//            result.push_back(vector<int>(curr_arr));
//            return;
//        }
//        for (int i = index; i < size; ++i) {
//            curr_arr.push_back(candidates[i]);
//            backtrack(curr_arr, candidates, i+1, target, size);
//            curr_arr.pop_back();
//        }
//        return;
//    }
//    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//        int size = (int)candidates.size();
//        if (size == 0) return result;
//
//        vector<int> temp;
//        backtrack(temp, candidates, 0, target, size);
//        helper(result);
//        return result;
//    }
    
    vector<vector<int>> result;
    unordered_map<int, bool> res_map;
    
    int getHashValue(vector<int>& array, int base, int mod) {
        int hashValue = 0;
        for (auto &num : array) {
            hashValue = 1LL * hashValue * base % mod + num;
            hashValue %= mod;
        }
        return hashValue;
    }
    
    void backtracking(vector<int> curr_arr, vector<int>& candidates, int start, int target) {
        int sum = accumulate(curr_arr.begin(), curr_arr.end(), 0);
        if (sum > target) return;
        if (sum == target) {
            sort(curr_arr.begin(), curr_arr.end(), less<int>());
            int hashValue = getHashValue(curr_arr, 2*target, 1e9+7);
            if (res_map.find(hashValue) == res_map.end()) {
                res_map[hashValue] = true;
                result.push_back(curr_arr);
            }
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            curr_arr.push_back(candidates[i]);
            backtracking(curr_arr, candidates, i+1, target);
            curr_arr.pop_back();
        }
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr_arr;
        backtracking(curr_arr, candidates, 0, target);
        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
