#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) {
            return "";
        }

        std::vector<int> countVec(256, 0);// A--z, 之间共72个位置
        auto check = [&]() {
            for(int i = 0; i < countVec.size(); ++i) {
                if(countVec[i] > 0) {
                    return false;
                }
            }

            return true;
        };
        for(int i = 0; i < t.size(); ++i) {
            countVec[t[i] - 'A']++;
            countVec[s[i] - 'A']--;
        }

        if(check()) {
            return s.substr(0, t.size());
        }

        int l = 0;
        int r = t.size();

        int minLen = s.size() + 1;
        std::pair<int, int> ret;
        for(; r < s.size(); r++) {
			//r指针移动
            countVec[s[r] - 'A']--;
            if(check()) {
                int curLen = r - l + 1;
                if(curLen <= minLen) {
                    minLen = curLen;
                    ret.first = l;
                    ret.second = r;
                }
            }

            while(check()) {
				// l指针移动
                int curLen = r - l + 1;
                if(curLen <= minLen) {
                    minLen = curLen;
                    ret.first = l;
                    ret.second = r;
                }
                countVec[s[l] - 'A']++;
                l++;
            }
        }

        return minLen != s.size() + 1
                   ? s.substr(ret.first, ret.second - ret.first + 1)
                   : "";
    }
};

int main() {

    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << Solution().minWindow(s, t) << endl;

    return 0;
}
