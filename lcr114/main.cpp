#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    string alienOrder(vector<string> &words) {

        unordered_map<char, vector<char>> orderMap;
        unordered_map<char, int> inMap;

        for(int i = 0; i < words.size(); ++i) {
            for(int j = 0; j < words[i].size(); ++j) {
                inMap[words[i].at(j)] = 0;
            }
        }

        for(int i = 1; i < words.size(); ++i) {
            int k = 0;
            for(; k < words[i - 1].size() && k < words[i].size();) {
                if(words[i - 1].at(k) != words[i].at(k)) {
                    orderMap[words[i - 1].at(k)].push_back(words[i].at(k));
                    inMap[words[i].at(k)]++;
                    k++;
                    break;
                } else {
                    k++;
                    continue;
                }
            }

            if(words[i - 1].at(k - 1) == words[i].at(k - 1) &&
               words[i - 1].size() > words[i].size()) {
                // "abc","ab"的情况
                return "";
            }
        }

        string str;
        for(auto it = inMap.begin(); it != inMap.end();) {
            if(it->second == 0) {
                str = str + it->first;
                // 重新计算入度
                auto chVec = orderMap[it->first];
                for(int i = 0; i < chVec.size(); ++i) {
                    inMap[chVec[i]]--;
                }

                it->second = -1;
                it = inMap.begin();
            } else {
                it++;
            }
        }

        if(str.size() == inMap.size()) {
            return str;
        } else {

            return "";
        }
    }
};
int main() { return 0; }
