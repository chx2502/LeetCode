#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        if (chars.length() == 0) return 0;
        vector<int> char_map(26, 0);

        for (auto &c : chars) {
            char_map[c-'a'] += 1;
        }

        int ret_length = 0;

        for (auto &word : words) {
            bool flag = true;
            int word_len = 0;
            vector<int> temp_map(char_map.begin(), char_map.end());
            for (auto &c : word) {
                word_len += 1;
                if (temp_map[c-'a'] == 0) {
                    flag = false;
                    break;
                }
                temp_map[c-'a'] -= 1;
            }
            if (flag) ret_length += word_len;
        }
        return ret_length;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
