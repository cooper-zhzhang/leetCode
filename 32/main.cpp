#include <algorithm>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#include <strings.h>
#include <vector>

using namespace std;
class Solution {
  public:
    int longestValidParentheses(string s) {
        size_t n = s.size();
        std::vector<int> dp(n, 0);
        int maxDp = 0;

        for(int i = 1; i < n; ++i) {

            if(s[i] == '(') {
                continue;
            }

            //()(())
            // s[i] == )
            if(s[i - 1] == ')') {

                if(dp[i - 1] > 0) {
                    int index = i - 1 - dp[i - 1];
                    if(index >= 0 && s[index] == '(') {
                        dp[i] = dp[i - 1] + 2;
                    } else {
                        dp[i] = 0;
                    }
                }
            } else {
                dp[i] = i - 2 >= 0 ? dp[i - 2] + 2 : 2;
            }

            // 最大的dp[i]
            // i-dp[i]
            if(i - dp[i] >= 0) {
                dp[i] = dp[i] + dp[i - dp[i] ];
            }
            maxDp = std::max(maxDp, dp[i]);
        }

        return maxDp;
    }
};


class Solution1 {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    maxans = max(maxans, i - stk.top());
                }
            }
        }
        return maxans;
    }
};



int main() {
    std::string s(")()())");

    // std::cout << Solution().longestValidParentheses(s) << std::endl;

    // std::cout << Solution().longestValidParentheses(std::string("()(())"))
    //           << std::endl;

    std::cout << Solution1().longestValidParentheses(std::string("()()"))
              << std::endl;



              

    return 0;
}
