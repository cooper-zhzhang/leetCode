#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;


        for(;l!=r;){
            int sum =numbers[l] + numbers[r]; 
            if(sum== target){
                return vector<int>{l+1, r+1};
            }

            if(sum < target){
                l++;
            }
            else {
                r--;
            }
        }


        return vector<int>{};
    }
};

int main() {


    vector<int> vec{2,7,11,15};
    for (auto it : Solution().twoSum(vec,9)) {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    return 0;

}



