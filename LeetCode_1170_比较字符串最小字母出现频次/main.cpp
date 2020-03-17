#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int f(const string& s) {
        int length = (int)s.length();
        vector<int> char_map(26, 0);
        for (auto &c : s) ++char_map[c-'a'];
        int result = 0;
        while (result < 26) {
            if (char_map[result] > 0) {
                result = char_map[result];
                break;
            }
            result++;
        }
        return result;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> answer;
        int q_size = (int)queries.size();
        int w_size = (int)words.size();
        if (q_size == 0) return answer;

        vector<int> array_Q;
        vector<int> array_W;
        for (auto &word : words) array_W.push_back(f(word));
        for (auto &query : queries) array_Q.push_back(f(query));
        for (int i = 0; i < q_size; ++i) {
            int count = 0;
            for (int j = 0; j < w_size; ++j) {
                if (array_Q[i] < array_W[j])
                    count += 1;
            }
            answer.push_back(count);
        }

        return answer;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
