/*
https://leetcode.cn/problems/product-of-array-except-self
*/
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {

        
        int n = nums.size();
        std::vector<int> l(n+1, 1);// i 表示 index i left
        
        for (int i = 1; i <= n; ++i) {
            l[i] = l[i-1]*nums[i-1];
        }

        std::vector<int> r(n+1, 1);
        for (int i = n - 2; i >= 0; i--) {
            r[i] = nums[i + 1] * r[i + 1];
        }


        std::vector<int> answer;
        for(int i = 0; i < n; ++i) {
            answer.push_back(l[i]*r[i]) ;
        }


        return answer;

    }
};

int main() {

    std::vector<int>nums{1,2,3,4};
    auto answer = Solution().productExceptSelf(nums);
    for(auto i : answer) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;

}


//8eFE4T2ifceSxca



