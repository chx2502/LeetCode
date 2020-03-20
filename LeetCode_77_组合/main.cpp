#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * 回溯算法求解，注意剪枝操作。
     * */
    vector<vector<int>> result;
    void backtrack(int i, vector<int> arr, int k, int n) {
        int size = (int)arr.size();
        if (size == k) {
            result.push_back(vector<int>(arr));
            return;
        }
        while (i <= n - (k - size) + 1) {
            arr.push_back(i);
            i++;
            backtrack(i, arr, k, n);
            arr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        backtrack(1, temp, k, n);
        return result;
    }
};

int main() {
    Solution s;
    int n = 4;
    int k = 2;
    s.combine(n, 2);
    return 0;
}
