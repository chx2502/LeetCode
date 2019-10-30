//
//  main.cpp
//  LeetCode_8_字符串转换整数 (atoi)
//
//  Created by chx on 2019/10/27.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

//#define MAX_INT 0x7FFFFFFF
//#define MIN_INT 0x80000000

class Solution {
    /*
     这题坑很多，把判断条件全弄清楚再写
     */
public:
    const int MAX_INT = 0x7FFFFFFF;
    const int MIN_INT = 0x80000000;
    
    int isLegalNum(string str) {
        const int ILLIGAL = -1;
        set<char> valid = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', '+'};
        
        unsigned long i, j;
        i = str.find_first_of("0123456789-+");
        if (i != 0 && str[0] != ' ') return ILLIGAL;
        if (i == string::npos) return ILLIGAL;
        j = str.find_last_of(' ');
        if (j != string::npos) {
            if (j < i) i = j + 1;
        }
        if (i >= str.length()) return ILLIGAL;
        
        int start_pos = (int)i;
        if (str[i] == '-' || str[i] == '+') i++;
        if ('0' <= str[i] && str[i] <= '9') return start_pos;
        else return ILLIGAL;
    }
    
    long string_to_num(string str) {
        int length = (int) str.length();

        long ret = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] < '0' || str[i] > '9') return ret;
            ret *= 10;
            ret += int(str[i] - '0');
            if (ret > MAX_INT)
                return ret;
        }
        return ret;
    }
    
    int myAtoi(string str) {
        int length = (int) str.length();
        const int ILLIGAL = 0;
        
        bool minus_sign = false;
        int start_pos = isLegalNum(str);
        if (start_pos == -1) return ILLIGAL;
        
        if (str[start_pos] == '-') {
            minus_sign = true;
            start_pos++;
        }
        if (str[start_pos] == '+') start_pos++;
        int end_pos = start_pos;
        while ('0' <= str[end_pos] && end_pos <= '9' && end_pos < length)
            end_pos++;
        
        long ret = string_to_num(str.substr(start_pos, end_pos - start_pos));
        if (minus_sign) {
            if (ret > MAX_INT) return MIN_INT;
            else return (-1) * (int)ret;
        }
        if (ret > MAX_INT) return MAX_INT;
        return (int)ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    string str = "2147483648";
    int result = s.myAtoi(str);
    std::cout << "Hello, World!\n" << s.MAX_INT << "\n" << s.MIN_INT << endl;
    return 0;
}
