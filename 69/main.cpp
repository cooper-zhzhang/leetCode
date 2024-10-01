#include <cmath>
#include <cstdlib>
#include <iostream>

class Solution {
  public:
    int mySqrt(int x) {
        if(x == 1) {
            return x;
        }
        double ret = sqrt(x, 0.00);

        return int(floor(ret));
    }
    double sqrt(double val, double reg) {

        // 0, val
        double startVal = 0;
        double endVal = val;

        double midVal = (startVal + endVal) / 2;

        // startVal..........mid.............endVal
        // val

        while(std::abs(midVal * midVal - val) > reg) {

            if(midVal * midVal > val) {
                endVal = midVal;
            } else {
                startVal = midVal;
            }

            midVal = (startVal + endVal) / 2;
        }

        // std::cout << std::endl;

        return midVal;
    }
};

class Solution1 {
  public:
    int mySqrt(int x) {

        if(x == 0) {
            return 0;
        }

        int l = 0;
        int r = x;
        int mid = x;
        int ans = -1;
        while(l <= r) {// 只要中间还有数字 则继续寻找

            mid = (l+r)/2;
            long long result  = (long long) mid * (long long)mid;
            if(result == x) {
                return mid;
            } else if(result <= x) {
                // 小于x，则记录，直到找到最接近的
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};

int main() {

    // std::cout << Solution1().mySqrt(0) << std::endl;
    // std::cout << Solution1().mySqrt(1) << std::endl;
    std::cout << Solution1().mySqrt(2) << std::endl;
    std::cout << Solution1().mySqrt(3) << std::endl;
    std::cout << Solution1().mySqrt(4) << std::endl;

    return 0;
}
