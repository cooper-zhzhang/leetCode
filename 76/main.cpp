// 712 625 847
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  public:
    int partition(vector<int> &nums, int l, int r) {
        int i = l;
        int value = nums[r];
        for(int j = l; j < r; ++j) {
            if(nums[j] < value) {
                std::swap(nums[j], nums[i]);
                ++i;
            }
        }
        swap(nums[i], nums[r]);
        return i;
    }
    int findTarget(vector<int> &nums, int l, int r, int index) {
        if(l >= r) {
            return nums[l];
        }
        int perIndex = partition(nums, l, r);
        if(index == perIndex) {
            return nums[index];
        } else if(index < perIndex) {
            return findTarget(nums, l, perIndex - 1, index);
        } else {
            return findTarget(nums, perIndex + 1, r, index);
        }
    }
    int findKthLargest(vector<int> &nums, int k) {
        int index = nums.size() - k; // index
        return findTarget(nums, 0, nums.size() - 1, index);
    }
};

int main() {

    vector<int> nums{3, 2, 1, 5, 6, 4};
    int k = 2;
    std::cout << Solution().findKthLargest(nums, k) << std::endl;
    return 0;
}
