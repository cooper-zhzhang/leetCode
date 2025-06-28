/*给定一个字符串 s ，请计算这个字符串中有多少个回文子字符串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

 

示例 1：


输入：s = "abc"
输出：3
解释：三个回文子串: "a", "b", "c"


示例 2：


输入：s = "aaa"
输出：6
解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"

 

提示：


	1 <= s.length <= 1000
	s 由小写英文字母组成


 

注意：本题与主站 70 题相同：https://leetcode-cn.com/problems/palindromic-substrings/ 

https://leetcode.cn/problems/a7VOhD


*/
class Solution {
  public:
    

    int countSubstrings(string str) {
        int count = 0;

        for(int i = 0; i < str.size(); ++i) {

            int l = i;
            int r = i;
            count += checkPalindrome(str, l, r);

            l = i;
            r = i + 1;
            count += checkPalindrome(str, l, r);
        }

        return count;
    }

private:
    int checkPalindrome(string &str, int l, int r) {

        int count = 0;
        while(r < str.size() && l >= 0) {

            if(str[l] == str[r]) {
                count++;
                l--;
                r++;
            } else {
                break;
            }
        }

        return count;
    }
};