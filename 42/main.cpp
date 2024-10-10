#include <algorithm>
#include <climits>
#include <vector>
#include <iostream>

using namespace std;

/*
接雨水
*/
class Solution {
  public:
    int trap(vector<int> &height) {

        // index表示所在位置左边和右边最高的数值
        int n = height.size();
        vector<int> l(n, 0);
        vector<int> r(n, 0);

        for(int i = 1; i < n; ++i) {
            l[i] = max(height[i-1], l[i - 1]);
        }

        for(int i = n - 2; i >= 0; --i) {
            r[i] = max(height[i+1], r[i + 1]);
        }

        int count = 0;
        for(int i = 0; i < n; ++i) {
            // 取决于三个值 左右和自己
            if(height[i] < l[i] && height[i] < r[i]) {
                // 在坑里才能够接住雨水
                count += min(l[i], r[i]) - height[i];
            }
        }

        return count;
    }
};

int main() { 
    
    vector<int>height {0,1,0,2,1,0,1,3,2,1,2,1};
    
    std::cout << 
    Solution().trap(height)
    << std::endl;
    
    return 0; }
