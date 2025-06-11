/*996. 平方数组的数目 - 如果一个数组的任意两个相邻元素之和都是 完全平方数 ，则该数组称为 平方数组 。

给定一个整数数组 nums，返回所有属于 平方数组 的 nums 的排列数量。

如果存在某个索引 i 使得 perm1[i] != perm2[i]，则认为两个排列 perm1 和 perm2 不同。

 

示例 1：


输入：nums = [1,17,8]
输出：2
解释：[1,8,17] 和 [17,8,1] 是有效的排列。


示例 2：


输入：nums = [2,2,2]
输出：1


 

提示：

 * 1 <= nums.length <= 12
 * 0 <= nums[i] <= 109
https://leetcode.cn/problems/number-of-squareful-arrays
*/
// 712 625 847
// 如果一个数组的任意两个相邻元素之和都是 完全平方数 ，则该数组称为 平方数组 。

/*
给定一个整数数组 nums，返回所有属于 平方数组 的 nums 的排列数量。

如果存在某个索引 i 使得 perm1[i] != perm2[i]，则认为两个排列 perm1 和 perm2
不同。

示例 1：

输入：nums = [1,17,8]
输出：2
解释：[1,8,17] 和 [17,8,1] 是有效的排列。

示例 2：

输入：nums = [2,2,2]
输出：1



提示：

    1 <= nums.length <= 12
    0 <= nums[i] <= 109

*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void squarefulPerms(vector<int> &nums, int index, vector<int> &ret,
                        int &count) {
        const int INVALID = -1;
        if(index == nums.size()) {
            count++;
        }

        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == INVALID) {
                continue;
            }
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            bool isValid = true;
            if(index > 0) {
                int sum = nums[i] + ret[index - 1];
                int temp = sqrt(sum);
                if(temp * temp != sum) {
                    isValid = false;
                }
            }

            if(isValid) {
                ret.push_back(nums[i]);
                int oldV = nums[i];
                nums[i] = INVALID;
                squarefulPerms(nums, index + 1, ret, count);
                ret.pop_back();
                nums[i] = oldV;
            } else {
                continue;
            }
        }
    }
    int numSquarefulPerms(vector<int> &nums) {
        int count = 0;
        vector<int> ret;
        sort(nums.begin(), nums.end());
        squarefulPerms(nums, 0, ret, count);
        return count;
    }
};

int main() {

    // vector<int> nums{1, 17, 8};
    vector<int> nums{2, 2, 2};
    std::cout << Solution().numSquarefulPerms(nums) << std::endl;

    return 0;
}
