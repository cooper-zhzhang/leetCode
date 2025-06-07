// 712 625 847
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
  public:
    ListNode *reverseBetween2(ListNode *head, int left, int right) {

        ListNode *it = head;
        for(int i = 0; i < left - 1; ++i) {
            it = it->next;
        }

        ListNode *pre = it;
        ListNode *newEnd = pre->next;
        it = newEnd->next;
        for(int i = left; i < right; ++i) {
            ListNode *temp = it;
            it = it->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        newEnd->next = it;

        return head;
    }
    ListNode *reverseBetween(ListNode *head, int left, int right) {

        int count = 1;
        ListNode *pre = nullptr;
        ListNode *next = nullptr;
        ListNode *start = nullptr;
        ListNode *end = nullptr;
        for(ListNode *it = head; it != nullptr; it = it->next) {
            if(count == left) {
                start = it;
            } else if(count == left - 1) {
                pre = it;
            } else if(count == right) {
                end = it;
                next = it->next;
                break;
            }

            count++;
        }

        // begin rev
        ListNode *newNode = nullptr;
        newNode = next;
        for(ListNode *it = start; it != next;) {
            ListNode *temp = it;
            it = it->next;
            temp->next = newNode;
            newNode = temp;
        }
        if(pre != nullptr) {
            pre->next = newNode;
        } else {
            return newNode;
        }
        return head;
    }
};
int main() {

    // 测试用例 1: [1, 2, 3, 4, 5], left = 2, right = 4
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    head = Solution().reverseBetween2(head, 2, 4);
    for(ListNode *it = head; it != nullptr; it = it->next) {
        std::cout << it->val << " ";
    }

    return 0;
}
