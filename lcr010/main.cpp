#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    int subarraySum(vector<int> &nums, int k) {

        int ret = 0;
        unordered_map<int, int> sumMap;
        int sum = 0;
        sumMap[sum]++;

        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            int need = sum - k;

            auto it = sumMap.find(need);
            if(it != sumMap.end()) {
                ret += it->second;
            }

            sumMap[sum]++;
        }

        return ret;
    }
};
int main() { return 0; }
