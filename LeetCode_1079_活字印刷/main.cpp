#include <iostream>
#include <string>
#include<vector>
#include <set>

using namespace std;

class Solution {
public:
//    vector<string> inspector;
    void backTracking(int begin, string curr, string tiles, set<string>& exist, int size, int& result) {
        int curr_length = curr.length();
        if (curr_length <= size && curr_length) {
            if (exist.find(curr) != exist.end()) return;
            else {
                exist.insert(curr);
//                inspector.push_back(curr);
            }
            result += 1;
        }
        for (int i = begin; i < size; ++i) {
            curr.push_back(tiles[i]);
            swap(tiles[begin], tiles[i]);
            backTracking(begin+1, curr, tiles, exist, size, result);
            curr.pop_back();
        }
    }

    int numTilePossibilities(string tiles) {
        int length = (int)tiles.length();
        if (length < 2) return length;
        int result = 0;
        set<string> exist;
        backTracking(0, "", tiles, exist, length, result);
        return result;
    }
};

int main() {
    string tiles = "AAB";
    Solution s;
    int res = s.numTilePossibilities(tiles);
    return 0;
}
