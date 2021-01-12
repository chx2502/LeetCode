//
//  main.cpp
//  LeetCode_349
//
//  Created by chx on 2020/11/2.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        set<int> numSet;
        for (auto num : nums1) numSet.insert(num);
        for (auto num : nums2) {
            if (numSet.count(num)) {
                result.push_back(num);
                numSet.erase(num);
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
