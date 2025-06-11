 class Solution {
  public:
    int countSubstrings(string str) {
        int count = 0;

        for(int i = 0; i < str.size(); ++i) {

            int l = i;
            int r = i;
            count += checkPalindrome(str, l, r);

            l = i;
            r = i + 1;
            count += checkPalindrome(str, l, r);
        }

        return count;
    }

  private:
    int checkPalindrome(string &str, int l, int r) {

        int count = 0;
        while(r < str.size() && l >= 0) {

            if(str[l] == str[r]) {
                count++;
                l--;
                r++;
            } else {
                break;
            }
        }

        return count;
    }
};
int main() { return 0; }
