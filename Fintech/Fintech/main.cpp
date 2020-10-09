#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

const int MAX = 1025;

int pyramid(vector<vector<int>>& matrix) {
    int size = (int)matrix.size();
    if (size == 1) return matrix[0][0];
    for (int level = size-2; level >= 0; --level) {
        int count = level+1;
        for (int pos = 0; pos < count; ++pos)
            matrix[level][pos] += max(matrix[level+1][pos], matrix[level+1][pos+1]);
    }
    
    return matrix[0][0];
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> matrix;
    for (int i = 1; i <= N; ++i) {
        vector<int> array;
        for (int j = 0; j < i; ++j) {
            int temp;
            cin >> temp;
            array.push_back(temp);
        }
        matrix.push_back(array);
    }
    int result = pyramid(matrix);
    cout << result;
}
