// 712 625 847
#include <vector>
using namespace std;

class Solution {
  public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {

        int sum = 1;

        int l = 0;
        int r = 0;

        int count = 0;
        for(; r < nums.size(); r++) {
            // 以r为结尾的子序列
            sum *= nums[r];

            while(l <= r && sum >= k) {
                sum /= nums[l];
                l++;
            }

            count += r >= l ? r - l + 1 : 0;
        }

        return count;
    }
};

int main() { return 0; }
