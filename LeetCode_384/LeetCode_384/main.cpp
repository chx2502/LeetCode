//
//  main.cpp
//  LeetCode_384
//
//  Created by chx on 2020/9/14.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>

using namespace std;

//class Solution {
//private:
//    vector<int> origin;
//    vector<vector<int>> shuffled;
//public:
//    Solution(vector<int>& nums) {
//        origin.assign(nums.begin(), nums.end());
//    }
//
//    vector<int> reset() {
//        return origin;
//    }
//
//    vector<int> shuffle() {
//        vector<int> result(origin.begin(), origin.end());
//        std::random_device rd;
//        std::mt19937 g(rd());
//        std::shuffle(result.begin(), result.end(), g);
//        return result;
//    }
//};

class Solution {
private:
    vector<int> origin;
public:
    Solution(vector<int>& nums) {
        origin.assign(nums.begin(), nums.end());
    }
    
    vector<int> reset() {
        return origin;
    }
    
    vector<int> shuffle() {
        vector<int> shuffled(origin.begin(), origin.end());
        int n = (int)shuffled.size();
        for (int i = 0; i < n; ++i) {
            swap(shuffled[i], shuffled[(rand()%(n-i)) + i]);
        }
        return shuffled;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
