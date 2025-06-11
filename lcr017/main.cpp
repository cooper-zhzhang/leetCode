/*LCR 017. 最小覆盖子串 - 给定两个字符串 s 和 t 。返回 s 中包含 t 的所有字符的最短子字符串。如果 s 中不存在符合条件的子字符串，则返回空字符串 "" 。

如果 s 中存在多个符合条件的子字符串，返回任意一个。

 

注意： 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。

 

示例 1：


输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC" 
解释：最短子字符串 "BANC" 包含了字符串 t 的所有字符 'A'、'B'、'C'

示例 2：


输入：s = "a", t = "a"
输出："a"


示例 3：


输入：s = "a", t = "aa"
输出：""
解释：t 中两个字符 'a' 均应包含在 s 的子串中，因此没有符合条件的子字符串，返回空字符串。

 

提示：

 * 1 <= s.length, t.length <= 105
 * s 和 t 由英文字母组成

 

进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？

 

注意：本题与主站 76 题相似（本题答案不唯一）：https://leetcode-cn.com/problems/minimum-window-substring/ [https://leetcode-cn.com/problems/minimum-window-substring/]
https://leetcode.cn/problems/M1oyTv
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) {
            return "";
        }

        std::vector<int> countVec(256, 0);// A--z, 之间共72个位置
        auto check = [&]() {
            for(int i = 0; i < countVec.size(); ++i) {
                if(countVec[i] > 0) {
                    return false;
                }
            }

            return true;
        };
        for(int i = 0; i < t.size(); ++i) {
            countVec[t[i] - 'A']++;
            countVec[s[i] - 'A']--;
        }

        if(check()) {
            return s.substr(0, t.size());
        }

        int l = 0;
        int r = t.size();

        int minLen = s.size() + 1;
        std::pair<int, int> ret;
        for(; r < s.size(); r++) {
			//r指针移动
            countVec[s[r] - 'A']--;
            if(check()) {
                int curLen = r - l + 1;
                if(curLen <= minLen) {
                    minLen = curLen;
                    ret.first = l;
                    ret.second = r;
                }
            }

            while(check()) {
				// l指针移动
                int curLen = r - l + 1;
                if(curLen <= minLen) {
                    minLen = curLen;
                    ret.first = l;
                    ret.second = r;
                }
                countVec[s[l] - 'A']++;
                l++;
            }
        }

        return minLen != s.size() + 1
                   ? s.substr(ret.first, ret.second - ret.first + 1)
                   : "";
    }
};

int main() {

    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << Solution().minWindow(s, t) << endl;

    return 0;
}
