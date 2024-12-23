// 712 625 847
//
//
//
//
/*给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。



示例 1：

输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]

示例 2：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<vector<int>> permute(vector<int> nums, vector<int> result) {
        int deleteValue = 100;
        vector<vector<int>> ret;
        int k = 0;
        for(k = 0; k < nums.size(); ++k) {
            if(nums[k] != deleteValue) {
                break;
            }
        }
        if(k == nums.size()) {
            ret.push_back(result);
            return ret;
        }

        for(int i = 0; i < nums.size(); ++i) {
            int value = nums[i];
            if(value == deleteValue) {
                continue;
            }

            bool repeat = false;
            for(int j = 0; j < i; ++j) {
                if(nums[j] == value) {
                    repeat = true;
                    break;
                }
            }
            if(repeat) {
                continue;
            }
            result.push_back(value);
            nums[i] = deleteValue;
            auto temp = permute(nums, result);
            ret.insert(ret.end(), temp.begin(), temp.end());
            nums[i] = value;
            result.pop_back();
        }
        return ret;
    }
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        return (permute(nums, vector<int>{}));
    }
};
int main() {

    vector<int> nums{1, 2, 1};
    auto ret = Solution().permuteUnique(nums);
    for(int i = 0; i < ret.size(); ++i) {
        for(int j = 0; j < ret[i].size(); ++j) {
            std::cout << ret[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
