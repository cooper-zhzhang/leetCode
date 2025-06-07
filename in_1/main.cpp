// 712 625 847

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int divide(int dividend, int divisor) {

    return INT32_MAX + 1;

    // return 0;
}

int signeNumber(vector<int> nums) {

    int bitCount[32]{0};
    for(auto value : nums) {

        int i = 0;
        while(value) {
            bitCount[i] += value & 1;
            value >>= 1;
            ++i;
        }
    }

    int result = 0;
    for(int i = 0; i < 32; ++i) {
        result = result + ((bitCount[i] % 3) << i);
    }

    return result;
}

int countBits(int num) {

    int *result = new int[num + 1]();

    // int result[num+1]={0};
    for(int i = 1; i <= num; ++i) {
        result[i] = result[i / 2] + i % 2;
    }

    int ret = 0;
    while(num) {
        if(num % 2 == 1) {
            ret++;
        }
        num = num >> 1;
    }

    return ret;
}

int maxProduct(vector<string> &words) {

    vector<int> dig(words.size(), 0);

    for(auto it = words.begin(); it != words.end(); ++it) {

        int x = 0;
        for(size_t i = 0; i < it->size(); ++i) {
            int index = it->at(i) - 'a';
            x |= 1 << index;
        }

        dig[it - words.begin()] = x;
    }

    int ret = 0;
    for(size_t i = 0; i < dig.size(); ++i) {
        for(size_t j = i + 1; j < dig.size(); ++j) {
            if((dig[i] & dig[j]) == 0) {
                ret = std::max(ret, int(words[i].size() * words[j].size()));
            }
        }
    }

    return ret;
}

vector<int> twoSum(const vector<int> &nums, int target) {

    vector<int> ret;

    unordered_map<int, int> numMap;

    for(int i = 0; i < nums.size(); ++i) {

        auto it = numMap.find(target - nums[i]);
        if(it != numMap.end()) {
            return vector<int>{i, it->second};
        }

        numMap[nums[i]] = i;
    }

    return ret;
}

int minSubArrLen(const vector<int> &nums, int target) {

    if(nums.size() <= 0) {
        return 0;
    }
    int l = 0;
    int r = 0;
    int ret = nums.size() + 1;

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

    return ret == nums.size() + 1 ? 0 : ret;
}

int nthUglyNumber(int n) {

	vector<int>dp(n, 0);
	dp[0] = 1;
	int index1= 0, index2= 0, index3 = 0;

	int i = 1;
	while (i < n) {
		dp[i] = std::min(std::min(dp[index1]*2, dp[index2]*3), dp[index3]*5);
		if(dp[i] == dp[index1]*2){
			index1++;
		} if(dp[i] == dp[index2]*3){
			index2++;
		} if (dp[i] == dp[index3]*5) {
			index3++;
		}

		i++;
	}


	return dp[n-1];
}

int main() {
    std::cout << nthUglyNumber(10);
    return 0;
}

