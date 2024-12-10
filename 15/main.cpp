#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i) {
            int first = nums[i];
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;

            int needNum = -first;
            while(j < k) {
                int twoSum = nums[j] + nums[k];
                if(twoSum == needNum) {
                    ret.push_back(vector<int>{first, nums[j], nums[k]});
                    while(j < k && nums[j] == nums[j + 1])
                        j++;
                    while(j < k && nums[k] == nums[k - 1])
                        k--;
                    j++;
                    k--;
                    continue;
                }
                if(twoSum > needNum) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return ret;
    }
};

int main() {

    // vector<int> vec{-2,0,0,2,2};
    vector<int> vec{-2, 0, 1, 1, 2};
    auto ret = Solution().threeSum(vec);
    for(auto &ve : ret) {
        for(auto &v : ve) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
