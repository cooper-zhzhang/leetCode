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
