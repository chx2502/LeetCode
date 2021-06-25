//
//  main.cpp
//  LeetCode_12
//
//  Created by chx on 2021/3/27.
//

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    unordered_map<int, string> translation = {
        {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"},
        {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"},
        {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"},
        {1000, "M"},
    };
    vector<int> base = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
    
    int nearest(int x) {
        int left = 0;
        int right = (int)base.size()-1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (x == base[mid]) return base[mid];
            if (x < base[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return base[right];
    }
    
public:
    string intToRoman(int num) {
        int neighbour = nearest(num);
        if (num == neighbour) return translation[neighbour];
        else if (num > neighbour) {
            return translation[neighbour] + intToRoman(num-neighbour);
        } else {
            return intToRoman(neighbour-num) + translation[neighbour];
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    int x = 1994;
    string res = s.intToRoman(x);
    return 0;
}
