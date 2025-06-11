/*76. 最小覆盖子串 - 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

 

注意：

 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案。

 

示例 1：


输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。


示例 2：


输入：s = "a", t = "a"
输出："a"
解释：整个字符串 s 是最小覆盖子串。


示例 3:


输入: s = "a", t = "aa"
输出: ""
解释: t 中两个字符 'a' 均应包含在 s 的子串中，
因此没有符合条件的子字符串，返回空字符串。

 

提示：

 * m == s.length
 * n == t.length
 * 1 <= m, n <= 105
 * s 和 t 由英文字母组成

 

进阶：你能设计一个在 o(m+n) 时间内解决此问题的算法吗？
https://leetcode.cn/problems/minimum-window-substring
*/
// 712 625 847
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  public:
    int partition(vector<int> &nums, int l, int r) {
        int i = l;
        int value = nums[r];
        for(int j = l; j < r; ++j) {
            if(nums[j] < value) {
                std::swap(nums[j], nums[i]);
                ++i;
            }
        }
        swap(nums[i], nums[r]);
        return i;
    }
    int findTarget(vector<int> &nums, int l, int r, int index) {
        if(l >= r) {
            return nums[l];
        }
        int perIndex = partition(nums, l, r);
        if(index == perIndex) {
            return nums[index];
        } else if(index < perIndex) {
            return findTarget(nums, l, perIndex - 1, index);
        } else {
            return findTarget(nums, perIndex + 1, r, index);
        }
    }
    int findKthLargest(vector<int> &nums, int k) {
        int index = nums.size() - k; // index
        return findTarget(nums, 0, nums.size() - 1, index);
    }
};

int main() {

    vector<int> nums{3, 2, 1, 5, 6, 4};
    int k = 2;
    std::cout << Solution().findKthLargest(nums, k) << std::endl;
    return 0;
}
