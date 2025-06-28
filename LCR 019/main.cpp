/*给定一个非空字符串 s，请判断如果 最多 从字符串中删除一个字符能否得到一个回文字符串。

 

示例 1：


输入: s = "aba"
输出: true


示例 2：


输入: s = "abca"
输出: true
解释: 可以删除 "c" 字符 或者 "b" 字符


示例 3：


输入: s = "abc"
输出: false

 

提示：


	1 <= s.length <= 105
	s 由小写英文字母组成


 

注意：本题与主站 680 题相同： https://leetcode-cn.com/problems/valid-palindrome-ii/

https://leetcode.cn/problems/RQku0D


*/

#include <string>
#include <iostream>

using namespace std;

class Solution {

	bool decChar;

	bool validPalindrome(string &s, int l , int r) {


		while(l < r){
			if(s[l] == s[r]){
				l++;
				r--;
			}else {
				if(decChar){
					return false;
				}
				decChar= true;
				return validPalindrome(s, l+1, r)||validPalindrome(s, l, r-1);
			}


		}

		return true;
    }

public:
    bool validPalindrome(string s) {


		int l = 0;
		int r = s.size()-1;

		return validPalindrome(s, l, r);
    }
};


int main(){

	string str("cbbcc");

	std::cout << Solution().validPalindrome(str) << std::endl;


	return 0;
}