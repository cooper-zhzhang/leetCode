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

#include <cstring>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>


using namespace std;



class FenwickArray {
    public:
    FenwickArray(int maxSize):MAXN(maxSize), bit(maxSize, 0){

    }

    void add(int i, int x) {
        while (i < MAXN) {
            bit[i] += x;
            i += lowbit(i);
        }
    }

    void sub(int i, int x) {
        while (i < MAXN) {
            bit[i] -= x;
            i += lowbit(i);
        }
    }

    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= lowbit(i);
        }
        return s;
    }
    private:
    vector<int>bit;
    int MAXN;

    int lowbit(int x) {
        return x&(-x);
    }
};


class Solution2 {
public:
    static const int MAXN = 10;
    int x[MAXN], y[MAXN];

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            x[i] = y[i] = nums[i];
        }

        FenwickArray fenArray(MAXN);

        sort(y, y + n);
        int len = unique(y, y + n) - y;
        for (int i = 0; i < n; ++i) {
            x[i] = lower_bound(y, y + len, x[i]) - y + 1;
        }

        vector<int> res;
        for (int i = n-1; i >= 0; --i) {
            res.push_back(fenArray.sum(x[i]-1));
            fenArray.add(x[i], 1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};




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
		vector<int>sortedNums;
		sortedNums.reserve(nums.size());
		for (int i = nums.size()-1; i >= 0; --i){
			int index = insert(sortedNums, nums[i]);
			ret[i] = index;
		}
		
		return ret;
    }
};

int main() {

	//vector<int> nums = {26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
	vector<int> nums ={5,2,6,1};
	auto ret = Solution2().countSmaller(nums);
	for (auto &v : ret){
		std::cout << v << " ";
	}

	std::cout << std::endl;

	return 0;
}




/*
lowbit(12) = 4
lowbit(11) = 1
lowbit(10) = 2
lowbit(9) = 1
lowbit(8) = 8
lowbit(7) = 1
lowbit(6) = 2
lowbit(5) = 1
lowbit(4) = 4
lowbit(3) = 1
lowbit(2) = 2
lowbit(1) = 1*/