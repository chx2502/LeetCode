#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * 核心思路：
     * 利用位运算，一个数第一次出现，其各 1 位保留，再次遇到时变回 0
     * 即：0 1 = 1 ，1 0 = 1， 1 1 = 0， 0 0 = 0
     * 分析以上规则，采用异或负号 ^，两位相异才保留
     * 最后剩下的 1 位构成了只出现 1 次的数
     * */
    int singleNonDuplicate(vector<int>& nums) {
        int result = 0;
        for (auto &num :nums) result = result ^ num;
        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
