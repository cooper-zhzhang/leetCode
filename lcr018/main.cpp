#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    bool isPalindrome(string s) {

        int l = 0;
        int r = s.size() - 1;

        while(l < r) {

            char lValue = 0;
            char rValue = 0;
            if(s[l] >= 'a' && s[l] <= 'z') {
                lValue = s[l];
            } else if(s[l] >= 'A' && s[l] <= 'Z') {
                lValue = s[l] - 'A' + 'a';
            } else if(s[l] >= '0' && s[l] <= '9') {
                lValue = s[l];
            } else {
                l++;
                continue;
            }

            if(s[r] >= 'a' && s[r] <= 'z') {
                rValue = s[r];
            } else if(s[r] >= 'A' && s[r] <= 'Z') {
                rValue = s[r] - 'A' + 'a';
            } else if(s[r] >= '0' && s[r] <= '9') {
                rValue = s[r];
            } else {
                r--;
                continue;
            }

            if(lValue == rValue) {
                l++;
                r--;
            } else {
                return false;
            }
        }

        return true;
    }
};

int main() {

    std::cout << Solution().isPalindrome(string("race a car")) << std::endl;

    return 0;
}
