#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

struct Hash {
    Hash() {
        bucketSize = 8;
        vecMap.resize(bucketSize);
    }
    int bucketSize;
    std::vector<std::vector<std::pair<int, int>>> vecMap;
    []-- > vector[k, v], [k, v][]

        void
        push(int k, int v) {
            int index = k % bucketSize;
            std::vector<std::pair<int, int>> &pairList = vecMap[index];
            for(auto &pairV : pairList) {
                if(pairV.first == k) {
                    pairV.second = v;
                    return;
                }
            }

            vecMap[index].push_back(std::make_pair(k, v));
        } void deleteK(int k) {
        int index = k % bucketSize;
        std::vector<std::pair<int, int>> &pairList = vecMap[index];
        for(auto it = pairList.begin(); it != pairList.end(); ++it) {
            if(it->first == k) {
                pairList.erase(it);
                return;
            }
        }
    }
};

int main() { return 0; }
