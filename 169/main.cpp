/*169. 多数元素 - 给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 

示例 1：


输入：nums = [3,2,3]
输出：3

示例 2：


输入：nums = [2,2,1,1,1,2,2]
输出：2


 

提示：
 * n == nums.length
 * 1 <= n <= 5 * 104
 * -109 <= nums[i] <= 109

 

进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
https://leetcode.cn/problems/majority-element
*/
#include <iostream>
#include <map>
#include <ostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        const int n = nums.size();
        std::map<int, long> elementMap;
        for (auto num : nums) {
            elementMap[num]++;
        }

        for (auto it = elementMap.begin(); it != elementMap.end(); ++it) {
            if (it->second > n / 2) {
                return it->first;
            }
        }
        return 0;
    }
};

int main() {

    std::vector<int> nums{2, 2, 1, 1, 1, 2, 2};
    Solution s;
    std::cout << s.majorityElement(nums) << std::endl;

    return 0;
}
