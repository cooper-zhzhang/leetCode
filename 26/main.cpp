// 712 625 847
#include <vector>
using namespace std;
class Solution {
  public:
    int removeDuplicates(vector<int> &nums) { 

      if(nums.size() == 0) return 0;

      int curIndex = 0;
      int checkIndex = 1;
      for(; checkIndex < nums.size(); checkIndex++) {
        if (nums[curIndex] != nums[checkIndex]) {
          curIndex++;
          nums[curIndex] = nums[checkIndex];
        }
      }

      return curIndex+1;

      }
};
int main() { return 0; }
