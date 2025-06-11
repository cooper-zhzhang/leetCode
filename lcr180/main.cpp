/*
https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof
*/
class Solution {
  public:
    vector<vector<int>> fileCombination(int target) {
        int l = 1;
        int r = 2;

        vector<vector<int>> ret;

        while(l < r && r < target) {
            int sum = (l + r) * (r - l + 1) / 2;
            if(sum == target) {
                vector<int> ans;
                for(int i = l; i <= r; ++i) {
                    ans.push_back(i);
                }
                ret.push_back(ans);
                l++;
            } else if(sum < target) {
                r++;
            } else {
                // sum > target
                l++;
            }
        }

        return ret;
    }
};
int main() { return 0; }
