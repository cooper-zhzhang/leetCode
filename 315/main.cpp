/*315. 计算右侧小于当前元素的个数 - 给你一个整数数组 nums ，按要求返回一个新数组 counts 。
 * 数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

 

示例 1：


输入：nums = [5,2,6,1]
输出：[2,1,1,0] 
解释：
5 的右侧有 2 个更小的元素 (2 和 1)
2 的右侧仅有 1 个更小的元素 (1)
6 的右侧有 1 个更小的元素 (1)
1 的右侧有 0 个更小的元素


示例 2：


输入：nums = [-1]
输出：[0]


示例 3：


输入：nums = [-1,-1]
输出：[0,0]


 

提示：

 * 1 <= nums.length <= 105
 * -104 <= nums[i] <= 104
https://leetcode.cn/problems/count-of-smaller-numbers-after-self
*
*/

#include <vector>
#include <iostream>
using namespace std;


class Solution {
	int insert(vector<int>& nums, int value){
		if(nums.empty()){
			nums.push_back(value);
			return 0;
		}

		int l  = 0;
		int r = nums.size();
		while(l < r){
			int index = (l+r)/2;
			if (nums[index] < value){
				l = index +1;
			}else {
				r = index;
			}
		}

		nums.insert(nums.begin()+l, value);
		return l;
	}
public:
    vector<int> countSmaller(vector<int>& nums) {

		vector<int> ret(nums.size(), 0);
		vector<int>sortedNums ;
		for (int i = nums.size()-1; i >= 0; --i){
			int index = insert(sortedNums, nums[i]);
			ret[i] = index;
		}
		
		return ret;
    }
};

int main() {

	vector<int> nums = {-1, -1};
	auto ret = Solution().countSmaller(nums);
	for (auto &v : ret){
		std::cout << v << " ";
	}

	std::cout << std::endl;

	return 0;
}