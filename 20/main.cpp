#include <iostream>
#include <ostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    bool isValid(string s) {

        unordered_map<char, char> pairs{{'}', '{'}, {')', '('}, {']', '['}};

        stack<char> tmp;
        for(auto i : s) {
            if(!pairs[i]) {
                tmp.push(i);
            } else {
                if(tmp.empty() || pairs[i] != tmp.top()) {
                    return false;
                }
                tmp.pop();
            }
        }

        return tmp.empty();
    }
};

class Solution1 {
  public:
    bool isValid(string s) {

        stack<char> tmp;
        for(auto i : s) {
            switch(i) {
            case '(':
            case '[':
            case '{':
                tmp.push(i);
                break;
            case ')':
                if(!popChar(tmp, '(')) {
                    return false;
                }

                break;
            case ']':
                if(!popChar(tmp, '[')) {
                    return false;
                }

                break;
            case '}':
                if(!popChar(tmp, '{')) {
                    return false;
                }

                break;
            }
        }

        return tmp.empty();
    }

    bool popChar(stack<char> &tmp, char c) {
        if(tmp.empty()) {
            return false;
        }
        if(tmp.top() != c) {
            return false;
        }

        tmp.pop();

        return true;
    }
};

int main() {

    std::cout << Solution().isValid("()") << std::endl;
    std::cout << Solution().isValid("()[]{}") << std::endl;
    std::cout << Solution().isValid("(]") << std::endl;
    std::cout << Solution().isValid("([])") << std::endl;

    std::cout << Solution().isValid("([)]") << std::endl;

    return 0;
}
