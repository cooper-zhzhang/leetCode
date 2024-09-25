#include <cstddef>
#include <iostream>
#include <vector>

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
        ListNode *resultNode = indexNode;

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

            firstPtr = firstPtr->next;

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

        if(tmpAdd > 0) {
            ListNode *tmpNode = new ListNode(tmpAdd);
            indexNode->next = tmpNode;
        }

        return resultNode;
    }
};

class Solution2 {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *firstPtr = l1;
        ListNode *secondPtr = l2;

        ListNode *indexNode = l1;
        ListNode *resultNode = l1;

        int tmpAdd = 0;
        int result = 0;

        int firstVal = 0;
        int secondVal = 0;
        while(firstPtr != NULL || secondPtr != NULL) {

            firstVal = secondVal = 0;
            if(firstPtr != nullptr) {
                firstVal = firstPtr->val;
                firstPtr = firstPtr->next;
            }

            if(secondPtr != nullptr) {
                secondVal = secondPtr->val;
                secondPtr = secondPtr->next;
            }

            result = firstVal + secondVal + tmpAdd;
            indexNode->val = result % 10;
            tmpAdd = result / 10;

            if(firstPtr != NULL || secondPtr != NULL) {
                // 需要有一个新的节点

                if(indexNode->next == nullptr) {
                    // 没有下一个节点，new一个
                    ListNode *tmpNode = new ListNode();
                    indexNode->next = tmpNode;
                }
                indexNode = indexNode->next;
            }
        }

        if(tmpAdd > 0) {
            ListNode *tmpNode = new ListNode(tmpAdd);
            indexNode->next = tmpNode;
        }

        return resultNode;
    }
};

ListNode *createList(std::vector<int> &ve);

void displayListNode(ListNode *l);
int main() {

    std::vector<int> ve1{9, 9, 9, 9, 9, 9, 9};
    std::vector<int> ve2{9, 9, 9, 9};

    ListNode *l1 = createList(ve1);
    ListNode *l2 = createList(ve2);

    displayListNode(l1);
    displayListNode(l2);

    displayListNode(Solution().addTwoNumbers(l1, l2));
    return 0;
}

void displayListNode(ListNode *l) {
    for(; l != NULL; l = l->next) {
        std::cout << l->val << " ";
    }

    std::cout << std::endl;
}

ListNode *createList(std::vector<int> &ve) {
    if(ve.size() == 0) {
        return NULL;
    }

    ListNode *root = new ListNode();
    ListNode *index = root;

    for(auto i : ve) {
        ListNode *tmpNode = new ListNode();
        tmpNode->val = i;
        index->next = tmpNode;
        index = index->next;
    }

    ListNode *ret = root->next;
    delete root;

    return ret;
}