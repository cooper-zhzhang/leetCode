/*
https://leetcode.cn/problems/search-in-rotated-sorted-array
*/
#include <vector>
using namespace std;
class Solution {
  public:
    int search(vector<int> &nums, int target) {
        if(nums.size() == 0) {
            return -1;
        }
        if(nums.size() == 1) {
            if(nums[0] == target) {
                return 0;
            }
            return -1;
        }

        int l = 0;
        int r = nums.size() - 1;
        int n = nums.size();
        while(l <= r) {
            int mid = (l + r) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            // l == mid 0 0 1
            if(nums[l] <= nums[mid]) {
                if(target >= nums[l] && target <= nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else { // mid---r
                if(target >= nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
