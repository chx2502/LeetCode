#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int size = (int)nums.size();
        if (size < 2) return false;
        
        map<int, pair<int, int>> indexMap;
        for (int i = 0; i < size; i++) {
            int curr = nums[i];
            auto it = indexMap.find(curr);
            if (it == indexMap.end()) indexMap[curr].first = indexMap[curr].second = i;
            else {
                if (i - it->second.second <= k) return true;
                it->second.second = i;
            }
        }

        sort(nums.begin(), nums.end());
        auto last = unique(nums.begin(), nums.end());
        nums.erase(last, nums.end());

        size = (int)nums.size();
        for (int i = 0; i < size-1; i++) {
            for (int j = i+1; j < size; j++) {
                long long diff = (long long)nums[j] - (long long)nums[i];
                if (diff > t) break;
                else {
                    if (abs(indexMap[nums[i]].first - indexMap[nums[j]].second) <= k || 
                    abs(indexMap[nums[j]].first - indexMap[nums[i]].second) <= k) return true;
                }
            }
        }
        return false;

    }
};

int main() {
    Solution s;
    vector<int> nums = {INT32_MIN, INT32_MAX};
    int k = 1;
    int t = 1;
    bool result = s.containsNearbyAlmostDuplicate(nums, k, t);
    cout << (result ? "true" : "false") << endl;
}