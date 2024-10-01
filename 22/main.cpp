#include <iostream>
#include <string>
#include <vector>

class Solution {
  public:
    std::vector<std::string> generateParenthesis(int n) {

        int l = 0;
        int r = 0;

        std::vector<std::string> vecResult;
        std::string str;
        build(l, r, n, str, vecResult);
        return vecResult;
    }

    void build(int l, int r, int n, std::string &strResult,
               std::vector<std::string> &vecResult) {

        // l == r 只能将l+1
        //  l < r 1-->l+1 2--> r + 1
        //  前提是都要少于n

        if(r == n) {
            vecResult.push_back(strResult);
            return;
        }

        if(l == r) {
            strResult .push_back('(');
            build(l+1, r, n, strResult, vecResult);
            strResult.pop_back();
        } else {
            // l != r
            // 1 l + 1
            // 2 r + 1
            if(l != n) {
                
                strResult.push_back('(');
                build(l + 1, r, n, strResult, vecResult);
                strResult.pop_back();
                

                strResult.push_back(')');
                build(l, r + 1, n, strResult, vecResult);
                strResult.pop_back();

            } else {
                strResult.push_back(')');
                build(l, r + 1, n, strResult, vecResult);
                strResult.pop_back();
            }
        }
    }
};


class Solution1 {
  public:
    std::vector<std::string> generateParenthesis(int n) {

        // digui
        int l = 0;
        int r = 0;

        std::vector<std::string> vecResult;
        std::string str(n*2, ' ');

        build(l, r, n, str, vecResult);
        return vecResult;
    }

    void build(int l, int r, int n, std::string &strResult,
               std::vector<std::string> &vecResult) {

        // l == r 只能将l+1
        //  l < r 1-->l+1 2--> r + 1
        //  前提是都要少于n

        if(r == n) {
            vecResult.push_back(strResult);
            return;
        }

        if(l == r) {
            strResult[l+r] = '(';
            build(l+1, r, n, strResult, vecResult);
        } else {
            // l != r
            // 1 l + 1
            // 2 r + 1
            if(l != n) {
                
                strResult[l+r] = '(';
                build(l + 1, r, n, strResult, vecResult);

                strResult[l+r] = ')';
                build(l, r + 1, n, strResult, vecResult);

            } else {
                strResult[l+r] = ')';
                build(l, r + 1, n, strResult, vecResult);
            }
        }
    }
};



int main() {

    auto ret = Solution1().generateParenthesis(3);
    for(auto &i : ret) {
        std::cout << i << " " << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
