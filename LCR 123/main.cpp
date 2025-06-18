/*LCR 123. 图书整理 I -
书店店员有一张链表形式的书单，每个节点代表一本书，节点中的值表示书的编号。
 * 为更方便整理书架，店员需要将书单倒过来排列，就可以从最后一本书开始整理，逐一将书放回到书架上。请倒序返回这个书单链表。

 

示例 1：


输入：head = [3,6,4,1]

输出：[1,4,6,3]


 

提示：

0 <= 链表长度 <= 10000
https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof
*/
// Definition for singly-linked list.

#include <stack>
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
    vector<int> reverseBookList(ListNode *head) {
        vector<int> ret;
        stack<int> st;

        while(head) {
            st.push(head->val);
            head = head->next;
        }

        while(!st.empty()) {
            ret.push_back(st.top());
            st.pop();
        }

        return ret;
    }
};
