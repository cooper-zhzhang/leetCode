/*
https://leetcode.cn/problems/VabMRr
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ret;
        if(p.size() > s.size()) {
            return ret;
        }

        vector<int> countVec(26, 0);

        auto checkCount = [&]() {
            for(int i = 0; i < countVec.size(); ++i) {
                if(countVec[i] != 0) {
                    return false;
                }
            }

            return true;
        };

        int i = 0;
        for(; i < p.size(); ++i) {
            countVec[p[i] - 'a']++;
            countVec[s[i] - 'a']--;
        }

        if(checkCount()) {
            ret.push_back(0);
        }

        int l = 1;
        int r = i;

        for(; r < s.size(); ++r, ++l) {
            countVec[s[r] - 'a']--;
            countVec[s[l - 1] - 'a']++;

            if(checkCount()) {
                ret.push_back(l);
            }
        }

        return ret;
    }
};

int main() {
    string s("cbaebabacd");
    string p("abc");

    auto ret = Solution().findAnagrams(s, p);

    for(auto v : ret) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    return 0;
}
