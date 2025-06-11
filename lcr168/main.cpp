/*LCR 168. 丑数 - 给你一个整数 n ，请你找出并返回第 n 个 丑数 。

说明：丑数是只包含质因数 2、3 和/或 5 的正整数；1 是丑数。

 

示例 1：


输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。

提示： 

 * 1 <= n <= 1690

 

注意：本题与主站 264 题相同：https://leetcode-cn.com/problems/ugly-number-ii/ [https://leetcode-cn.com/problems/ugly-number-ii/]

 
https://leetcode.cn/problems/chou-shu-lcof
*/
#include <algorithm>
#include <cstdarg>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        int index1 = 0, index2 = 0, index3 = 0;

        int value1 = dp[index1] * 2;
        int value2 = dp[index2] * 3;
        int value3 = dp[index3] * 5;

        int i = 1;
        while(i < n) {
            dp[i] = std::min({value1, value2, value3});
            if(dp[i] == value1) {
                index1++;
                value1 = dp[index1] * 2;
            }
            if(dp[i] == value2) {
                index2++;
                value2 = dp[index2] * 3;
            }
            if(dp[i] == value3) {
                index3++;
                value3 = dp[index3] * 5;
            }

            i++;
        }

        return dp[n - 1];
    }
};
int main() {

    for(int i = 1; i < 100; ++i) {
        std::cout << Solution().nthUglyNumber(i) << " ";
    }

    return 0;
}
