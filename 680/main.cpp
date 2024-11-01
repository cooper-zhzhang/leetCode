/*
验证回文串 II*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    bool check(string &s, int i, int j, bool del) {

        while(s[i] == s[j] && i < j) {
            i++;
            j--;
        }

        if(i >= j) {
            return true;
        }

        if(del) {
            return false;
        }

        return check(s, i + 1, j, true) || check(s, i, j - 1, true);
    }

    bool validPalindrome(string s) { return check(s, 0, s.size() - 1, false); }
};

int main() {

    std::cout << Solution().validPalindrome(std::string("aba")) << std::endl;
    return 0;
}