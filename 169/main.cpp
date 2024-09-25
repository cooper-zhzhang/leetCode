#include <iostream>
#include <map>
#include <ostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        const int n = nums.size();
        std::map<int, long> elementMap;
        for (auto num : nums) {
            elementMap[num]++;
        }

        for (auto it = elementMap.begin(); it != elementMap.end(); ++it) {
            if (it->second > n / 2) {
                return it->first;
            }
        }
        return 0;
    }
};

int main() {

    std::vector<int> nums{2, 2, 1, 1, 1, 2, 2};
    Solution s;
    std::cout << s.majorityElement(nums) << std::endl;

    return 0;
}
