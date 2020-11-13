//
//  main.cpp
//  LeetCode_1356
//
//  Created by chx on 2020/11/6.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, int> memory;
public:
    int count(int num) {
        int temp = num;
        int result = 0;
        while(temp) {
            if (memory.count(num)) {
                result += memory[temp];
                break;
            }
            if (temp&1) result++;
            temp >>= 1;
        }
        memory[num] = result;
        return result;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
//        vector<int> result(arr.begin(), arr.end());
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int ac = count(a);
            int bc = count(b);
            if (ac == bc) return a < b;
            else return ac < bc;
        });
        return arr;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> arr = { 0,1,2,3,4,5,6,7,8 };
    int c = s.count(6);
    vector<int> result = s.sortByBits(arr);
    return 0;
}
