//
//  main.cpp
//  LeetCode_118
//
//  Created by chx on 2020/12/16.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> generateNextRow(vector<int> row) {
        if (row.size() == 1) return {1, 1};
        int p, q;
        p = 0;
        vector<int> result;
        result.push_back(row[p]);
        while (p < row.size()-1) {
            q = p+1;
            result.push_back(row[p] + row[q]);
            p++;
        }
        result.push_back(row[p]);
        return result;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows == 0) return result;
        result.push_back({1});
        int n = 1;
        while (n < numRows) {
            result.push_back(generateNextRow(result[n-1]));
            n++;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
