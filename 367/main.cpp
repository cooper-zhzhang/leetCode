#include <cmath>
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 0 || num == 1) {
            return true;
        }

        int l = 0;
        int r = num;
        int mid = num;
        while(l <= r) {// 只要中间还有数字 则继续寻找
            mid = (l+r)/2;
            long long result  = (long long) mid * (long long)mid;
            if(result == num) {
                return true;
            } else if(result < num) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return false;
    }
};

int main() {

    return 0;
}



