// 712 625 847

class Solution {
  public:
    int minSubArrayLen(int target, vector<int> &nums) {
        if(nums.size() <= 0) {
            return 0;
        }
        int l = 0;
        int r = 0;
        int NOT_FOUND = nums.size() + 1;
        int ret = NOT_FOUND;

        int sum = nums[0];
        while(l <= r && r < nums.size()) {

            if(sum >= target) {
                ret = min(ret, r - l + 1);
                sum -= nums[l];
                l++;
            } else {
                r++;
                if(r < nums.size())
                    sum += nums[r];
            }
        }

        return ret == NOT_FOUND ? 0 : ret;
    }
};
int main() { return 0; }
