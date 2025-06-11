/*61. 旋转链表 - 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

 

示例 1：

[https://assets.leetcode.com/uploads/2020/11/13/rotate1.jpg]


输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]


示例 2：

[https://assets.leetcode.com/uploads/2020/11/13/roate2.jpg]


输入：head = [0,1,2], k = 4
输出：[2,0,1]


 

提示：

 * 链表中节点的数目在范围 [0, 500] 内
 * -100 <= Node.val <= 100
 * 0 <= k <= 2 * 109
https://leetcode.cn/problems/rotate-list
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/**
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
class Solution {
  public:
    ListNode *rotateRight(ListNode *head, int k) {
        // 1计算长度
        // 2 计算分割点
        // 3 找到新的头
        // 4组装
        int len = 0;
        ListNode *tempH = head;
        while(tempH) {
            tempH = tempH->next;
            len++;
        }
        k = k % len;
        if(k == 0) {
            return head;
        }
        k = len - k;
        ListNode *newH = head;
        ListNode *newE = head;
        for(int i = 0; i < k; ++i) {
            newE = newH;
            newH = newH->next;
        }
        ListNode *temp = new(ListNode);
        temp->next = newH;
        ListNode *it = newH;
        while(it->next != nullptr) {
            it = it->next;
        }
        it->next = head;
        it = it->next;
        while(it != newE) {
            it = it->next;
        }
        it->next = nullptr;

        head = temp->next;
        delete temp;

        return head;
    }
};

void display(ListNode *h) {
    while(h) {
        std::cout << h->val << " ";
        h = h->next;
    }
    std::cout << std::endl;
}
int main() {

    ListNode *head = new ListNode;
    ListNode *curHead = head;
    vector<int> vec{1, 2, 3, 4, 5};
    for(auto &it : vec) {
        ListNode *temp = new ListNode(it);
        head->next = temp;
        head = temp;
    }
    display(curHead->next);

    head = Solution().rotateRight(curHead->next, 6);
    display(head);
    return 0;
}
