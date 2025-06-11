/*633. 平方数之和 - 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 。

 

示例 1：


输入：c = 5
输出：true
解释：1 * 1 + 2 * 2 = 5


示例 2：


输入：c = 3
输出：false


 

提示：

 * 0 <= c <= 231 - 1
https://leetcode.cn/problems/sum-of-square-numbers
*/
#include <cmath>
#include <iostream>

class Solution {
  public:
    bool judgeSquareSum(int c) {

        long endVal = (long)std::floor((std::sqrt(c)));
        for(long i = 0; i <= endVal; ++i) {
            long b = floor(std::sqrt(c - i * i));
            if(i * i + b * b == c) {
                return true;
            }
        }

        return false;
    }
};

int main() {

    std::cout << Solution().judgeSquareSum(1) << std::endl;
    std::cout << Solution().judgeSquareSum(2) << std::endl; // 1 * 1 + 1 * 1
    std::cout << Solution().judgeSquareSum(3) << std::endl;
    std::cout << Solution().judgeSquareSum(4) << std::endl;
    std::cout << Solution().judgeSquareSum(5) << std::endl; // 1* 1 + 2* 2 = 5
    std::cout << Solution().judgeSquareSum(6) << std::endl;

    return 0;
}
