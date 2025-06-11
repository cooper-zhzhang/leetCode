/*2099. 找到和最大的长度为 K 的子序列 - 给你一个整数数组 nums 和一个整数 k 。你需要找到 nums 中长度为 k 的 子序列 ，且这个子序列的 和最大 。

请你返回 任意 一个长度为 k 的整数子序列。

子序列 定义为从一个数组里删除一些元素后，不改变剩下元素的顺序得到的数组。

 

示例 1：

输入：nums = [2,1,3,3], k = 2
输出：[3,3]
解释：
子序列有最大和：3 + 3 = 6 。

示例 2：

输入：nums = [-1,-2,3,4], k = 3
输出：[-1,3,4]
解释：
子序列有最大和：-1 + 3 + 4 = 6 。


示例 3：

输入：nums = [3,4,3,3], k = 2
输出：[3,4]
解释：
子序列有最大和：3 + 4 = 7 。
另一个可行的子序列为 [4, 3] 。


 

提示：

 * 1 <= nums.length <= 1000
 * -105 <= nums[i] <= 105
 * 1 <= k <= nums.length
https://leetcode.cn/problems/find-subsequence-of-length-k-with-the-largest-sum
*/
// 712 625 847
class Solution {
  public:
    int comp(std::pair<int, int> &v1, std::pair<int, int> &v2) {
        if(v1.second < v2.second) {
            return -1;
        }

        if(v1.second > v2.second) {
            return 1;
        }

		if (v1.first < v2.first){
			return -1;
		}
		
		return 1;
    }

    int findMaxK(std::vector<std::pair<int, int>> &vec, int l, int r,
                 int targetK) {

        int i = l;
        int j = l;
        int k = r + 1;

        std::pair<int, int> midValue = vec[i];

        for(; i < k;) {
            int compRet = comp(vec[i], midValue);
            if(compRet == -1) {
                // 小于midvalue
                std::swap(vec[i], vec[j]);
                i++;
                j++;
            } else if(compRet == 0) {
                //==
                i++;
            } else {
                // > midValue
                k--;
                std::swap(vec[i], vec[k]);
            }
        }
        //[l, j-1], [j, k-1], [k, r] ok
        int orderMaxCount = r-k+1;
		if(orderMaxCount == targetK){
			return 0;
		}else if(orderMaxCount > targetK){
   			return findMaxK(vec, k, r, targetK);
		}else {
			// targetK > orderMaxCount
			targetK = targetK - orderMaxCount;
			int equalCount = k-1-j+1;
			if(equalCount >= targetK){
				// 相等的部分足够了
				return 0;
			}
			targetK=targetK-equalCount;
			return findMaxK(vec, l, j-1, targetK);
		}

    }
    std::vector<int> maxSubsequence(std::vector<int> &vec, int k) {
        if(vec.size() <= k) {
            return vec;
        }
        std::vector<std::pair<int, int>> pairVec;
        for(int i = 0; i < vec.size(); ++i) {
            pairVec.push_back({i, vec[i]});
        }

        findMaxK(pairVec, 0, pairVec.size() - 1, k);

        std::vector<std::pair<int, int>> PairRet(
            pairVec.begin() + pairVec.size() - k, pairVec.end());

        sort(PairRet.begin(), PairRet.end(),
             [](std::pair<int, int> &v1, std::pair<int, int> &v2) {
                 return v1.first < v2.first;
             });

        std::vector<int> ret;
        for(int i = 0; i < PairRet.size(); ++i) {
            ret.push_back(PairRet[i].second);
        }

        return ret;
    }
};
int main() { return 0; }
