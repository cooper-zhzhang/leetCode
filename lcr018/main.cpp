/*LCR 018. 验证回文串 - 给定一个字符串 s ，验证 s 是否是 回文串 ，只考虑字母和数字字符，可以忽略字母的大小写。

本题中，将空字符串定义为有效的 回文串 。

 

示例 1：


输入: s = "A man, a plan, a canal: Panama"
输出: true
解释："amanaplanacanalpanama" 是回文串

示例 2：


输入: s = "race a car"
输出: false
解释："raceacar" 不是回文串

 

提示：

 * 1 <= s.length <= 2 * 105
 * 字符串 s 由 ASCII 字符组成

 

注意：本题与主站 125 题相同： https://leetcode-cn.com/problems/valid-palindrome/ [https://leetcode-cn.com/problems/valid-palindrome/]
https://leetcode.cn/problems/XltzEq
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    bool isPalindrome(string s) {

        int l = 0;
        int r = s.size() - 1;

        while(l < r) {

            char lValue = 0;
            char rValue = 0;
            if(s[l] >= 'a' && s[l] <= 'z') {
                lValue = s[l];
            } else if(s[l] >= 'A' && s[l] <= 'Z') {
                lValue = s[l] - 'A' + 'a';
            } else if(s[l] >= '0' && s[l] <= '9') {
                lValue = s[l];
            } else {
                l++;
                continue;
            }

            if(s[r] >= 'a' && s[r] <= 'z') {
                rValue = s[r];
            } else if(s[r] >= 'A' && s[r] <= 'Z') {
                rValue = s[r] - 'A' + 'a';
            } else if(s[r] >= '0' && s[r] <= '9') {
                rValue = s[r];
            } else {
                r--;
                continue;
            }

            if(lValue == rValue) {
                l++;
                r--;
            } else {
                return false;
            }
        }

        return true;
    }
};

int main() {

    std::cout << Solution().isPalindrome(string("race a car")) << std::endl;

    return 0;
}
