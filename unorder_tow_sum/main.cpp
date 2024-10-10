#include <iostream>
#include <map>
#include <vector>

std::vector<int> find(std::vector<int> nums, int sum) {
    std::map<int, int> numsMap;

    std::vector<int> resultVec;

    for(int i = 0; i < nums.size(); ++i) {
        numsMap[nums[i]]++;
    }

    for(auto it = numsMap.begin(); it != numsMap.end();) {
        if(it->second <= 0) {
            ++it;
            continue;
        }

        (it->second)--;
        int needNum = sum - it->first;
        if(numsMap[needNum] > 0) {
            numsMap[needNum]--;
            resultVec.push_back(it->first);
            resultVec.push_back(needNum);
            // 找到了 如果 it.second > 0再找一次
            if(it->second > 0) {
                continue;
            }
        }

        it++;
    }

    return resultVec;
}

int main() {

    std::vector<int> ret = find(
        std::vector<int>{101, 80, -1, 50, 1000000, 100, 20, 30, 50, 20, 50, 50},
        100);

    for(int i = 0; i < ret.size(); ++i) {
        if(i % 2 == 0) {
            std::cout << "{" << ret[i] << ",";
        }

        if(i % 2 != 0) {
            std::cout << ret[i] << "}" << std::endl;
        }
    }

    return 0;
}

/*

数组：{101, 80, -1, 50, 1000000, 100, 20, 30, 50, 20, 50, 50}

K = 100

O(N)时间 空间复杂度内，找到所有加和等于K的数对。原数组中每个数字只能使用一次。

{-1, 101}
{20, 80}
{50, 50}
{50, 50}

*/