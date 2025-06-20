/*1143. 最长公共子序列 - 给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

 * 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。

两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。

 

示例 1：


输入：text1 = "abcde", text2 = "ace" 
输出：3  
解释：最长公共子序列是 "ace" ，它的长度为 3 。


示例 2：


输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc" ，它的长度为 3 。


示例 3：


输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0 。


 

提示：

 * 1 <= text1.length, text2.length <= 1000
 * text1 和 text2 仅由小写英文字符组成。
https://leetcode.cn/problems/longest-common-subsequence
*/
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <type_traits>
#include <vector>

class Solution {
  public:
    int lcs(std::string &text1, std::string text2,
            std::vector<std::vector<int>> &ve) {

        if(text1.size() == 0 || text2.size() == 0) {
            return 0;
        }

        int count1 = 0;
        int count2 = 0;
        int count3 = 0;

        if(ve[text1.size()][text2.size()] >= 0) {
            return ve[text1.size()][text2.size()];
        }

        if(text1.at(text1.size() - 1) == text2.at(text2.size() - 1)) {
            count1 =
                longestCommonSubsequence(text1.substr(0, text1.size() - 1),
                                         text2.substr(0, text2.size() - 1)) +
                1;
        } else {
            count2 = longestCommonSubsequence(text1.substr(0, text1.size() - 1),
                                              text2.substr(0, text2.size()));

            count3 =
                longestCommonSubsequence(text1.substr(0, text1.size()),
                                         text2.substr(0, text2.size() - 1));
        }

        int retCount = std::max(std::max(count1, count2), count3);

        ve[text1.size()][text2.size()] = retCount;

        return retCount;
    }

    int longestCommonSubsequence(std::string text1, std::string text2) {
        int retCount = 0;

        // static int [text1.size()][text2.size()] c;// {-1};

        if(text1.size() == 0 || text2.size() == 0) {
            return retCount;
        }

        std::vector<std::vector<int>> c;

        for(size_t i = 0; i < text1.size() + 1; ++i) {
            std::vector<int> tmp(text2.size() + 1, -1);
            c.push_back(tmp);
        }

        return lcs(text1, text2, c);
    }
};

class Solution1 {
  public:
    int longestCommonSubsequence(std::string text1, std::string text2) {

        std::vector<std::vector<int>> c;
        for(size_t i = 0; i < text1.size() + 1; ++i) {
            std::vector<int> tmp(text2.size() + 1, -1);
            c.push_back(tmp);
        }

        // c下标数字表示第一个和第二个链表中剩余的字符个数
        for(size_t i = 0; i < c.size(); ++i) {
            c[i][0] = 0;
        }

        for(size_t j = 0; j < text2.size() + 1; ++j) {
            c[0][j] = 0;
        }

        for(size_t i = 1; i < c.size(); i++) {
            for(size_t j = 1; j < c[i].size(); j++)

                if(text1[i - 1] == text2[j - 1]) {
                    c[i][j] = c[i - 1][j - 1] + 1;
                } else {
                    c[i][j] = std::max(c[i - 1][j], c[i][j - 1]);
                }
        }

        return c[text1.size()][text2.size()];
    }
};

int main() {

    std::string text1 = "hofubmnylkra";
    std::string text2 = "pqhgxgdofcvmr";

    std::cout << Solution().longestCommonSubsequence(text1, text2) << std::endl;

    return 0;
}
