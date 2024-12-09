#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    int threeSumClosest(vector<int> &nums, int target) {
        if(nums.size() < 3) {
            return 0;
        }

        std::sort(nums.begin(), nums.end());
        // 随便选择三个值作为结果
        int ans = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size(); ++i) {
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if(abs(sum - target) < abs(ans - target)) {
                    // 当前的sum更接近target
                    ans = sum;
                }
                if(ans == target) {
                    return ans;
                } else if(sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return ans;
    }
};
