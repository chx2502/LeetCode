#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /*
    核心思路：
    一次遍历完成。没遇到一个和上一个不同的字符 c，则开始计算其连续出现的数量，记为 bias。
    返回结果 result = result + c + to_string(bias)，同时将遍历指针 i 移动到 c 结束的位置。
    最后比较 result 和 参数 S 的长度，返回短的那一个。
    **/
    string compressString(string S) {
        int length = (int)S.length();
        if (length == 1) return S;

        string result;

        for (int i = 0; i < length; ++i) {
            char c = S[i];
            int bias = 1;
            result.push_back(c);
            while (S[i+bias] == c) ++bias;
            i = i+bias-1;
            result += to_string(bias);
        }
        return result.length() < length ? result : S;
    }
};

int main() {
    Solution s;
    string S = "aabcccccaaa";
    string result = s.compressString(S);
    return 0;
}