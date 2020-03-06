#include <iostream>
#include <vector>

using namespace std;

/*
 * 求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
 * 输入: n = 9
 * 输出: 45
 */

class Solution {
public:
    /*
     * 题目本身并不难，但是限制使用各种循环和判断语句，需要寻找替代。
     * 问题分析：
     * sumSums(n) = n + sumSums(n-1)， n > 0；
     * 当 n == 0 时，应返回 0，所以需要一个替代品来实现 if (n == 0) return 0；
     * 利用 && 运算符的特点，A && B 在 A = false 时不会执行 B 语句
     * 故 n > 0 可以作为判断语句来控制递归的退出。
     * */
    int sumNums(int n) {
        int result = n;
        bool tmp = (n > 0) && (result += sumNums(n-1));
        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
