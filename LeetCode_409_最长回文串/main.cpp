#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int length = (int)s.length();
        if (length == 0) return 0;

        vector<int> char_map(128, 0);
//        map<char, int> char_map;
        int result = 0;
        for (auto &c : s) {
            char_map[c] += 1;
            if (char_map[c] % 2 == 0)
                result += 2;
        }
        if (result < length) result += 1;
        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
