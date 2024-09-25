#include <iostream>
#include <vector>

class Solution {
  public:
    int removeDuplicates(std::vector<int> &nums) {

        int n = nums.size();
        int sameCount = 1;

        for (int i = 1; i < n; i++) {

            if (nums[i] == nums[i - 1]) {
                sameCount++;
            } else {
                if (sameCount > 2) {
                    // deal move num
                    int curDel = sameCount - 2;
                    int pos = i - curDel;
                    int start = i;
                    int sum = n - i;
                    copy(nums, pos, start, sum);
                    n = n - curDel;
                    i = pos - 1;
                }
                sameCount = 1;
            }
        }

        if (sameCount > 2) {
            int curDel = sameCount - 2;
            n = n - curDel;
        }

        return n;
    }

    void copy(std::vector<int> &nums, int pos, int start, int sum) {

        if (pos >= start) {
            return;
        }
        for (int i = 0; i < sum; ++i) {
            nums[pos++] = nums[start++];
        }
    }
};

int main() {

    std::vector<int> nums{0, 0, 1, 1, 1, 1, 2, 3, 3};

    Solution s;
    int n = s.removeDuplicates(nums);

    std::cout << n << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << nums[i] << " ";
    }

    return 0;
}

int removeDuplicates(std::vector<int> &nums) {

    // 双指针法
    int n = nums.size();
    if (n <= 2) {
        return n;
    }

    int slow = 2, fast = 2;
    while (fast < n) {
        if (nums[slow - 2] != nums[fast]) {
            nums[slow] = nums[fast];
            ++slow;
        }

        ++fast;
    }

    return slow;
}