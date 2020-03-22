#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        const int left = 0b0111100000;
        const int right = 0b0000011110;
        const int mid = 0b0001111000;
        map<int, int> seatMap;
        int rowCount = 0;
        for (auto &array : reservedSeats) {
            int row = array[0];
            int seats = seatMap[row];
            seats = seats | (1 << (10-array[1]));
            seatMap[row] = seats;
        }
        int result = 0;
        for (auto iter = seatMap.begin(); iter != seatMap.end(); ++iter) {
            ++rowCount;
            int seats = iter->second;
            int temp = 0;
            if ((left & seats) == 0) temp += 1;
            if ((right & seats) == 0) temp += 1;
            if (temp == 0) {
                if ((seats & mid) == 0) temp += 1;
            }
            result += temp;
        }
        result += (n-rowCount) * 2;
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> reservedSeats = {
            {1, 10},
            {1, 9},
            {1, 8},
            {2, 6},
            {3, 1},
            {3, 10}
    };
    int n = 3;
    int result = s.maxNumberOfFamilies(n, reservedSeats);
    return 0;
}
