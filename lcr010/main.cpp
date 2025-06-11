/*LCR 010. 和为 K 的子数组 - 给定一个整数数组和一个整数 k ，请找到该数组中和为 k 的连续子数组的个数。

 

示例 1：


输入:nums = [1,1,1], k = 2
输出: 2
解释: 此题 [1,1] 与 [1,1] 为两种不同的情况


示例 2：


输入:nums = [1,2,3], k = 3
输出: 2


 

提示:

 * 1 <= nums.length <= 2 * 104
 * -1000 <= nums[i] <= 1000

 * -107 <= k <= 107

 

注意：本题与主站 560 题相同： https://leetcode-cn.com/problems/subarray-sum-equals-k/ [https://leetcode-cn.com/problems/subarray-sum-equals-k/]
https://leetcode.cn/problems/QTMn0o
*/
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    int subarraySum(vector<int> &nums, int k) {

        int ret = 0;
        unordered_map<int, int> sumMap;
        int sum = 0;
        sumMap[sum]++;

        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            int need = sum - k;

            auto it = sumMap.find(need);
            if(it != sumMap.end()) {
                ret += it->second;
            }

            sumMap[sum]++;
        }

        return ret;
    }
};
int main() { return 0; }
