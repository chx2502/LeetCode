//
//  main.cpp
//  LeetCode_179
//
//  Created by chx on 2021/3/3.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string result;
        auto cmp = [&](int a, int b) {
            string sa = to_string(a);
            string sb = to_string(b);
            
            if (sa[0] == sb[0]) {
                string ab, ba;
                ab = sa+sb;
                ba = sb+sa;
                return stoll(ab) > stoll(ba);
            } else return sa[0] > sb[0];
        };
        sort(nums.begin(), nums.end(), cmp);
        for (auto &num : nums) {
            result += to_string(num);
            if (result.compare("0") == 0) result = "";
        }
        return result == "" ? "0" : result;
    }
};

int main(int argc, const char * argv[]) {

    return 0;
}
