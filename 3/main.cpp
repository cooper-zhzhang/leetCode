/*3. 无重复字符的最长子串 - 给定一个字符串 s ，请你找出其中不含有重复字符的 最长
子串 的长度。

 

示例 1:


输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。


示例 2:


输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。


示例 3:


输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。


 

提示：

 * 0 <= s.length <= 5 * 104
 * s 由英文字母、数字、符号和空格组成
https://leetcode.cn/problems/longest-substring-without-repeating-characters
*/
#include <string>
#include <unordered_map>

using namespace std;
int lengthOfLongestSubstring(string str) {
    if(str.size() <= 1) {
        return str.size();
    }

    unordered_map<char, int> subStrIndexMap;
    int len = 0;
    int maxLen = 0;
    int subBeginIndex = 0;

    for(int i = 0; i < str.size(); ++i) {
        char c = str[i];
        auto it = subStrIndexMap.find(c);
        if(it == subStrIndexMap.end() || it->second < subBeginIndex) {
            len++;
            maxLen = std::max(maxLen, len);
        } else {
            len = i - it->second;
            subBeginIndex = it->second + 1;
        }
        subStrIndexMap[c] = i;
    }

    return maxLen;
}

int main() { return 0; }
