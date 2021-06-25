//
//  main.cpp
//  offer_67
//
//  Created by chx on 2021/4/23.
//

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    int strToInt(string str) {
        unsigned long length = str.length();
        if (length == 0) return 0;
        int low, high;
        low = 0;

        while (low < length && str.at(low) == ' ') low++;
        if (low == length) return 0;
        if (str.at(low) == '-' || str.at(low) == '+') low++;
        if (low == length || isdigit(str.at(low)) == 0) return 0;
        high = low;
        
        long long num = 0;
        while (high < length && isdigit(str.at(high)) != 0) {
            num = num * 10 + (str.at(high) - '0');
            if (num > INT32_MAX) break;
            high++;
        }
        
        if (low > 0 && str.at(low-1) == '-') num *= -1;
        
        if (num > INT32_MAX) num = INT32_MAX;
        if (num < INT32_MIN) num = INT32_MIN;
        
        return (int)num;
    }
};

int main(int argc, const char * argv[]) {
    string str = "20000000000000000000";
    Solution s;
    int result = s.strToInt(str);
    return 0;
}
