//
//  main.cpp
//  offer_66
//
//  Created by chx on 2021/4/22.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int mul = 1;
        int zeroCount = 0;
        for (const int &num : a) {
            if (num == 0) {
                zeroCount++;
                continue;
            }
            mul *= num;
        }
        vector<int> result;
        for (const int &num : a) {
            if (num == 0 && zeroCount < 2) result.push_back(mul);
            else {
                if (zeroCount) result.push_back(0);
                else result.push_back(int(mul * (1.0/num)));
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
