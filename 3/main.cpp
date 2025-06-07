#include <string>
#include <unordered_map>

using namespace std;
int lengthOfLongestSubstring(string str) {
    if(str.size() <= 1) {
        return str.size();
    }

    unordered_map<char, int> subStrIndexMap;
    int len = 0;
    int maxLen = 0;
    int subBeginIndex = 0;

    for(int i = 0; i < str.size(); ++i) {
        char c = str[i];
        auto it = subStrIndexMap.find(c);
        if(it == subStrIndexMap.end() || it->second < subBeginIndex) {
            len++;
            // i - subBeginIndex+1;
            maxLen = std::max(maxLen, len);
        } else {
            len = i - it->second;
            subBeginIndex = it->second + 1;
        }
        subStrIndexMap[c] = i;
    }

    return maxLen;
}

int main() { return 0; }
