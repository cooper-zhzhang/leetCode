#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size()) {
            return false;
        }

        vector<int> vec(26, 0);

        auto checkFound = [&]() {
            for(int i = 0; i < vec.size(); ++i) {
                if(vec[i] != 0) {
                    return false;
                }
            }

            return true;
        };

        int i = 0;
        for(i = 0; i < s1.size(); ++i) {
            vec[s1[i] - 'a']++;
            vec[s2[i] - 'a']--;
        }

        if(checkFound()) {
            return true;
        }

        int l = 1;
        int r = i;
        for(; r < s2.size(); ++r, ++l) {
            vec[s2[r] - 'a']--;
            vec[s2[l - 1]-'a']++;

            if(checkFound()) {
                return true;
            }
        }

        return false;
    }
};

int main() {

    string s1 = "ab";
    string s2 = "eidbaooo";

	std::cout << 
	Solution().checkInclusion(s1, s2) << std::endl;
        return 0;
}
