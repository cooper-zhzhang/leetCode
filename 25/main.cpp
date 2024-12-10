// 25. K 个一组翻转链表
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(k <= 1 || head == nullptr) {
            return head;
        }

        ListNode *it = head;
        int i = 0;
        while(i < k - 1 && it->next != nullptr) {
            it = it->next;
            ++i;
        }

        // 1 判断是否需要 翻转
        if(i != k - 1 || it == nullptr) {
            return head;
        }
        ListNode *nextAH = it->next;

        //        head -->-- >  -->--- tempH
        //             head ---<---<---<--tempH
        ListNode *end = it;
        ListNode *tempH = it;
        ListNode *tempNode = new(ListNode);

        it = head;
        while(it != end) {
            ListNode *nextIt = it->next;
            it->next = tempNode->next;
            tempNode->next = it;
            it = nextIt;
        }
        tempH->next = tempNode->next;
        delete tempNode;
        head->next = reverseKGroup(nextAH, k);
        // 返回新的node
        return tempH;
    }
};

void displayNode(ListNode *h) {
    while(h) {
        std::cout << h->val << " ";
        h = h->next;
    }
    std::cout << std::endl;
}
int main() {

    ListNode *root = new ListNode;
    ListNode *itNode = root;
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8};
    for(auto &it : vec) {
        ListNode *temp = new ListNode(it);
        itNode->next = temp;
        itNode = temp;
    }
    ListNode *head = root->next;
    displayNode(root->next);
    head = Solution().reverseKGroup(head, 3);
    displayNode(head);

    return 0;
}
