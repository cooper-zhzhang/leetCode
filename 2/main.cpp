#include <cstddef>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution1 {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *firstPtr = l1;
        ListNode *secondPtr = l2;

        ListNode *indexNode = new ListNode(0);
        ListNode *resultNode = indexNode;

        int tmpAdd = 0;
        int result = 0;

        int firstVal = 0;
        int secondVal = 0;

        while(firstPtr != NULL || secondPtr != NULL) {

            firstVal = secondVal = 0;
            if(firstPtr != nullptr) {
                firstVal = firstPtr->val;
                firstPtr = firstPtr->next;
            } else {
            }

            if(secondPtr != nullptr) {
                secondVal = secondPtr->val;
                secondPtr = secondPtr->next;
            } else {
            }

            result = firstVal + secondVal + tmpAdd;
            indexNode->val = result % 10;
            tmpAdd = result / 10;

            if(firstPtr != NULL || secondPtr != NULL) {
                ListNode *tmpNode = new ListNode();

                indexNode->next = tmpNode;
                indexNode = tmpNode;
            }
        }

        if(tmpAdd > 0) {
            ListNode *tmpNode = new ListNode(tmpAdd);
            indexNode->next = tmpNode;
        }

        return resultNode;
    }
};


class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *firstPtr = l1;
        ListNode *secondPtr = l2;

        ListNode *indexNode = new ListNode(0);
        ListNode *resultNode = indexNode ;
        

        int tmpAdd = 0;
        int result = 0;
        while(firstPtr != NULL && secondPtr != NULL) {
            
            result = firstPtr->val + secondPtr->val + tmpAdd;

            indexNode->val = result % 10;
            tmpAdd = result / 10;

            firstPtr = firstPtr->next;
            secondPtr = secondPtr->next;

            if(firstPtr != NULL || secondPtr != NULL) {
                ListNode *tmpNode = new ListNode();

                indexNode->next = tmpNode;
                indexNode = tmpNode;
            }
        }

        while(firstPtr != NULL) {

            result = tmpAdd + firstPtr->val;
            indexNode->val = result % 10;
            tmpAdd = result / 10;

            firstPtr = firstPtr ->next;

            if(firstPtr != NULL) {
                ListNode *tmpNode = new ListNode();

                indexNode->next = tmpNode;
                indexNode = tmpNode;
            }
        }

         while(secondPtr != NULL) {

            result = tmpAdd + secondPtr->val;
            indexNode->val = result % 10;
            tmpAdd = result / 10;

            secondPtr = secondPtr->next;
            if(secondPtr != NULL) {
                ListNode *tmpNode = new ListNode();
                indexNode->next = tmpNode;
                indexNode = tmpNode;
            }
        }


        if (tmpAdd > 0) {
                ListNode *tmpNode = new ListNode(tmpAdd);
                indexNode->next = tmpNode;
        }

        return resultNode ;
    }
};

int main() { return 0; }
