/*206. 反转链表 - 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

 

示例 1：

[https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg]


输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]


示例 2：

[https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg]


输入：head = [1,2]
输出：[2,1]


示例 3：


输入：head = []
输出：[]


 

提示：

 * 链表中节点的数目范围是 [0, 5000]
 * -5000 <= Node.val <= 5000

 

进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
https://leetcode.cn/problems/reverse-linked-list
*/
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
