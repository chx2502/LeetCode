//
//  main.cpp
//  LeetCode_1431
//
//  Created by chx on 2020/6/1.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int size = (int)candies.size();
        int most = -1;
        vector<bool> result;
        for (auto num : candies) {
            most = max(most, num);
        }
        for (auto & num : candies) {
            if (num + extraCandies >= most)
                result.push_back(true);
            else result.push_back(false);
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
