#include <iostream>

using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        int result = 0;
        for (int i = 0; i < n; i++) {
            result ^= start;
            start += 2;
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    return 0;
}