/*25. K 个一组翻转链表 - 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。

k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

 

示例 1：

[https://assets.leetcode.com/uploads/2020/10/03/reverse_ex1.jpg]


输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]


示例 2：

[https://assets.leetcode.com/uploads/2020/10/03/reverse_ex2.jpg]


输入：head = [1,2,3,4,5], k = 3
输出：[3,2,1,4,5]


 

提示：
 * 链表中的节点数目为 n
 * 1 <= k <= n <= 5000
 * 0 <= Node.val <= 1000

 

进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？
https://leetcode.cn/problems/reverse-nodes-in-k-group
*/
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
