#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

class Solution1 {
  public:
    int hIndex(std::vector<int> &citations) {

        std::sort(citations.begin(), citations.end());
        int h = 0;
        for(auto it = citations.rbegin(); it != citations.rend(); ++it) {
            int count = it - citations.rbegin() + 1;
            if(*it >= count) {
                h = count;
            } else {
                break;
            }
        }

        return h;
    }
};

class Solution {
  public:
    int hIndex(std::vector<int> &citations) {

        int sumCitation = 0;
        for(auto citation : citations) {
            sumCitation += citation;
        }

        int h = int(std::trunc(std::sqrt(sumCitation)));
        for(; h >= 0; h--) {

            int count = 0;
            for(size_t i = 0; i < citations.size(); ++i) {

                if(citations[i] >= h) {
                    ++count;
                }
            }

            if(count >= h) {
                return h;
            }
        }

        return h;
    }
};

int main() {

    std::vector<int> nums{3, 0, 6, 1, 5};

    std::cout << Solution1().hIndex(nums) << std::endl;
    return 0;
}

// 8eFE4T2ifceSxca
