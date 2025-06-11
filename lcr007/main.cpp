/*LCR 007. 三数之和 - 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a ，b ，c ，使得 a + b + c = 0 ？请找出所有和为 0 且 不重复 的三元组。

 

示例 1：


输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]


示例 2：


输入：nums = []
输出：[]


示例 3：


输入：nums = [0]
输出：[]


 

提示：

 * 0 <= nums.length <= 3000
 * -105 <= nums[i] <= 105

 

注意：本题与主站 15 题相同：https://leetcode-cn.com/problems/3sum/ [https://leetcode-cn.com/problems/3sum/]
https://leetcode.cn/problems/1fGaJU
*/
// 712 625 847
class Solution {

  public:
    vector<vector<int>> ret;

    void twoSum(vector<int> &vec, int i) {
        int j = i + 1;
        int k = vec.size() - 1;

        while(j < k) {
            int sum = vec[i] + vec[j] + vec[k];
            if(sum == 0) {
                // get
                ret.push_back({vec[i], vec[j], vec[k]});

                int temp = vec[j];
                while(j < k && vec[j] == temp) {
                    j++;
                }

            } else if(sum < 0) {
                j++;

            } else {
                k--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int> &vec) {

        if(vec.size() < 3) {
            return ret;
        }
        sort(vec.begin(), vec.end());

        for(int i = 0; i < vec.size();) {
            twoSum(vec, i);
            int temp = vec[i];
            while(i < vec.size() && vec[i] == temp) {
                i++;
            }
        }

        return ret;
    }
};

int main() { return 0; }
