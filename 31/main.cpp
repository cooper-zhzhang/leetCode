/*31. 下一个排列 - 整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。

 * 例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。

整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的 下一个排列 就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。

 * 例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
 * 类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
 * 而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。

给你一个整数数组 nums ，找出 nums 的下一个排列。

必须 原地 [https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95]修改，只允许使用额外常数空间。

 

示例 1：


输入：nums = [1,2,3]
输出：[1,3,2]


示例 2：


输入：nums = [3,2,1]
输出：[1,2,3]


示例 3：


输入：nums = [1,1,5]
输出：[1,5,1]


 

提示：

 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 100
https://leetcode.cn/problems/next-permutation
*/
// 712 625 847
//
/*
 *
 * 整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。

例如，arr = [1,2,3] ，以下这些都可以视作 arr
的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。 整数数组的 下一个排列
是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的
下一个排列
就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。

例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1]
不存在一个字典序更大的排列。 给你一个整数数组 nums ，找出 nums 的下一个排列。

必须 原地 修改，只允许使用额外常数空间。



示例 1：

输入：nums = [1,2,3]
输出：[1,3,2]
示例 2：

输入：nums = [3,2,1]
输出：[1,2,3]
示例 3：

输入：nums = [1,1,5]
输出：[1,5,1]

*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    void nextPermutation(vector<int> &nums) {
        int i = nums.size() - 1;
        int len = nums.size();
        bool changed = false;
        for(; i >= 0; --i) {
            int curValue = nums[i];
            int j = i + 1;
            int findValue = 1000;
            int findIndex = -1;
            while(j < len) {
                if(nums[j] > curValue && nums[j] < findValue) {
                    findValue = nums[j];
                    findIndex = j;
                }
                j++;
            }
            if(findValue != 1000) {
                changed = true;
                int temp = nums[i];
                nums[i] = nums[findIndex];
                nums[findIndex] = temp; // 重组后面的
                sort(nums.begin() + i + 1, nums.end());
                break;
            }
        }
        if(!changed) {
            sort(nums.begin(), nums.end());
        }
    }
};
int main() {
    vector<int> vec{1, 1, 5};
    Solution().nextPermutation(vec);
    for(auto &i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
