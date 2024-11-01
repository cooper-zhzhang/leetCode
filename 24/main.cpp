/**
    两两交换链表中的节点

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1 {
  public:
    ListNode *swapPairs(ListNode *head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
    }
};

class Solution {
  public:
    ListNode *change(ListNode *curNode) {
        //分冶
        if(curNode == nullptr || curNode->next == nullptr) {
            return curNode;
        }

        ListNode *nextNode = curNode->next;
        curNode->next = nextNode->next;
        nextNode->next = curNode;

        return nextNode;
    }

    ListNode *swapPairs(ListNode *head) {
        if(head == nullptr) {
            return head;
        }

        ListNode *lastNode = new ListNode();
        ListNode *RetHead = lastNode;

        ListNode *tmpNode = head;
        while(tmpNode) {
            ListNode *node = change(tmpNode);
            lastNode->next = node;

            lastNode = node->next;
            if(lastNode != nullptr && lastNode->next != nullptr) {
                tmpNode = lastNode->next;
            } else {
                tmpNode = nullptr;
            }
        }

        head = RetHead->next;
        delete RetHead;
        return head;
    }
};

int main() { return 0; }
