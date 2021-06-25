#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, vector<int>> indexMap;
public:
    int countTriplets(vector<int>& arr) {
        unsigned long size = arr.size();
        if (size < 2) return 0;

        vector<int> memory(size);
        memory[0] = arr[0];
        for (int i = 1; i < size; i++) {
            memory[i] = arr[i]^memory[i-1];
        }

        // for (int i = 0; i < size; i++) {
        //     auto it = indexMap.find(arr[i]);
        //     if (it == indexMap.end()) indexMap[arr[i]].push_back(i);
        //     else it->second.push_back(i);
        // }
        int result = 0;
        for (int i = 0; i < size; i++) {
            for (int j = i+1; j < size; j++) {
                for (int k = j; k < size; k++) {
                    int xor_ij;
                    if (i == 0) xor_ij = memory[j-1];
                    else xor_ij = memory[i-1]^memory[j-1];
                    int xor_jk = memory[j-1]^memory[k];
                    if (xor_ij == xor_jk) result++;
                }
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> arr = {2, 3, 1, 6, 7};
    int result = s.countTriplets(arr);
    cout << "result = " << result << endl;
    return 0;
}