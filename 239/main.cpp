/*
https://leetcode.cn/problems/sliding-window-maximum
*/
/*2、给定一个长度为N的数组，
 * 经过一个长度为N的窗口，每次滑动一个元素，
 * 计算窗口内的最大值并打印，直到数组滑出窗口。
 * 给你一个整数数组 nums，有一个大小为 k
的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
个数字。滑动窗口每次只向右移动一位。

返回 滑动窗口中的最大值 。
O(n*logk)



示例 1：

输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
 */

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        if(k == 1) {
            return nums;
        }

        vector<int> ret;
        if(k > nums.size() || k <= 0) {
            return ret;
        }
        priority_queue<std::pair<int, int>> queue;
        for(int i = 0; i < k; ++i) {
            // queue.push(std::make_pair(nums[i], i));
            queue.emplace(nums[i], i);
        }
        ret.push_back(queue.top().first);

        for(int i = k; i < nums.size(); ++i) {
            while(queue.top().second <= i - k) {
                queue.pop();
            }
            queue.emplace(nums[i], i);
            // queue.push(std::make_pair(nums[i], i));
            ret.push_back(queue.top().first);
        }
        return ret;
    }
};

int main() {

    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    auto ret = Solution().maxSlidingWindow(nums, k);
    for(auto v : ret) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    return 0;
}
