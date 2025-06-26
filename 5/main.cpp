/*给你一个字符串 s，找到 s 中最长的 回文 子串。



示例 1：


输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。


示例 2：


输入：s = "cbbd"
输出："bb"




提示：


        1 <= s.length <= 1000
        s 仅由数字和英文字母组成


https://leetcode.cn/problems/longest-palindromic-substring


*/
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
class Solution {
  public:
    string longestPalindrome(string s) {
        if(s.size() == 0 || s.size() == 1) {
            return s;
        }

        int maxLen = 0;
        std::pair<int, int> retPair{0, 0};
        auto f = [&](int l, int r) {
            while(l >= 0 && r < s.size()) {
                if(s[l] == s[r]) {
                    if(maxLen < r - l + 1) {
                        retPair = {l, r};
                        maxLen = r - l + 1;
                    }
                    l--;
                    r++;

                } else {
                    return;
                }
            }
        };

        for(int i = 0; i < s.size(); ++i) {
            f(i - 1, i + 1);
            f(i, i + 1);
        }

        return s.substr(retPair.first, retPair.second - retPair.first + 1);
    }
};

int main() {

    std::cout << Solution().longestPalindrome("babad") << std::endl;
    return 0;
}