/*LCR 009. 乘积小于 K 的子数组 - 给定一个正整数数组 nums和整数 k ，请找出该数组内乘积小于 k 的连续的子数组的个数。

 

示例 1：


输入: nums = [10,5,2,6], k = 100
输出: 8
解释: 8 个乘积小于 100 的子数组分别为: [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]。
需要注意的是 [10,5,2] 并不是乘积小于100的子数组。


示例 2：


输入: nums = [1,2,3], k = 0
输出: 0

 

提示：

 * 1 <= nums.length <= 3 * 104
 * 1 <= nums[i] <= 1000
 * 0 <= k <= 106

 

注意：本题与主站 713 题相同：https://leetcode-cn.com/problems/subarray-product-less-than-k/ [https://leetcode-cn.com/problems/subarray-product-less-than-k/] 
https://leetcode.cn/problems/ZVAVXX
*/
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
