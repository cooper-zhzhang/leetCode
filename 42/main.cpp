/*42. 接雨水 - 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

 

示例 1：

[https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/rainwatertrap.png]


输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 


示例 2：


输入：height = [4,2,0,3,2,5]
输出：9


 

提示：

 * n == height.length
 * 1 <= n <= 2 * 104
 * 0 <= height[i] <= 105
https://leetcode.cn/problems/trapping-rain-water
*/
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

/*
接雨水
*/
class Solution {
  public:
    int trap(vector<int> &height) {

        // index表示所在位置左边和右边最高的数值
        int n = height.size();
        vector<int> l(n, 0);
        vector<int> r(n, 0);

        for(int i = 1; i < n; ++i) {
            l[i] = max(height[i - 1], l[i - 1]);
        }

        for(int i = n - 2; i >= 0; --i) {
            r[i] = max(height[i + 1], r[i + 1]);
        }

        int count = 0;
        for(int i = 0; i < n; ++i) {
            // 取决于三个值 左右和自己
            if(height[i] < l[i] && height[i] < r[i]) {
                // 在坑里才能够接住雨水
                count += min(l[i], r[i]) - height[i];
            }
        }

        return count;
    }
};

int main() {

    vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    std::cout << Solution().trap(height) << std::endl;

    return 0;
}
