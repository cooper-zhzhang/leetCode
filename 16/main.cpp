/*16. 最接近的三数之和 - 给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。

返回这三个数的和。

假定每组输入只存在恰好一个解。

 

示例 1：


输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2)。


示例 2：


输入：nums = [0,0,0], target = 1
输出：0
解释：与 target 最接近的和是 0（0 + 0 + 0 = 0）。

 

提示：

 * 3 <= nums.length <= 1000
 * -1000 <= nums[i] <= 1000
 * -104 <= target <= 104
https://leetcode.cn/problems/3sum-closest
*/
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    int threeSumClosest(vector<int> &nums, int target) {
        if(nums.size() < 3) {
            return 0;
        }

        std::sort(nums.begin(), nums.end());
        // 随便选择三个值作为结果
        int ans = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size(); ++i) {
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if(abs(sum - target) < abs(ans - target)) {
                    // 当前的sum更接近target
                    ans = sum;
                }
                if(ans == target) {
                    return ans;
                } else if(sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return ans;
    }
};
