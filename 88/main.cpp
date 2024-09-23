#include <iostream>
#include <vector>

class Solution {
public:
  void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {

    int index = m + n - 1; // insert value pos

    int i = m - 1;
    int j = n - 1;
    for (; i >= 0 && j >= 0;) {
      // 比较大的值放在最后
      if (nums1[i] >= nums2[j]) {
        nums1[index--] = nums1[i--];
      } else {
        nums1[index--] = nums2[j--];
      }
    }

    while (j >= 0) {
      nums1[index--] = nums2[j--];
    }
  }
};

int main() {

  std::vector<int> nums1{1, 2, 3, 0, 0, 0};
  int m = 3;

  std::vector<int> nums2{2, 5, 6};
  int n = 3;

  Solution s;
  s.merge(nums1, m, nums2, n);

  for (auto it = nums1.begin(); it != nums1.end(); ++it) {
    std::cout << *it << " ";
  }

  std::cout << std::endl;

  return 0;
}