// 712 625 847
#include <cstddef>
#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *it = nullptr;
        for(it = head; it != nullptr;) {
            ListNode *temp = it;
            it = it->next;
            temp->next = pre;
            pre = temp;
        }

        return pre;
    }
};

void initListNode(std::vector<int> ve) {
    for(auto it = ve.begin(); it != ve.end(); ++it) {
    }
}
int main() { return 0; }
