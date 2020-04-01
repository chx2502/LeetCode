#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void backTracking(int begin, int size, vector<int>& curr, vector<int>& nums, vector<vector<int>>& result) {
        if (curr.size() <= size) {
            result.push_back(curr);
        }
        for (int i = begin; i < size; ++i) {
            if (i > begin && nums[i] == nums[i-1]) continue;
            int temp = nums[i];
            curr.push_back(temp);
            backTracking(i+1, size, curr, nums, result);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int size = (int)nums.size();
        vector<vector<int>> result;
        if (size == 0) return result;
        vector<int> curr;
        sort(nums.begin(), nums.end(), less<int>());
        backTracking(0, size, curr, nums, result);
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = s.subsetsWithDup(nums);
    return 0;
}
