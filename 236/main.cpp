/*236. 二叉树的最近公共祖先 - 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科 [https://baike.baidu.com/item/%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88/8918834?fr=aladdin]中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

 

示例 1：

[https://assets.leetcode.com/uploads/2018/12/14/binarytree.png]


输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出：3
解释：节点 5 和节点 1 的最近公共祖先是节点 3 。


示例 2：

[https://assets.leetcode.com/uploads/2018/12/14/binarytree.png]


输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出：5
解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。


示例 3：


输入：root = [1,2], p = 1, q = 2
输出：1


 

提示：

 * 树中节点数目在范围 [2, 105] 内。
 * -109 <= Node.val <= 109
 * 所有 Node.val 互不相同 。
 * p != q
 * p 和 q 均存在于给定的二叉树中。
https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree
*/
// 712 625 847
#include <list>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    bool findNodeDir(list<TreeNode *> &nodeList, TreeNode *target) {

        auto root = nodeList.back();
        if(root->left != nullptr) {
            nodeList.push_back(root->left);
            if(root->left == target || findNodeDir(nodeList, target)) {
                return true;
            }

            nodeList.pop_back();
        }

        if(root->right != nullptr) {
            nodeList.push_back(root->right);
            if(root->right == target || findNodeDir(nodeList, target)) {
                return true;
            }

            nodeList.pop_back();
        }

        return false;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *target1,
                                   TreeNode *target2) {
        if(root == nullptr) {
            return nullptr;
        }

        list<TreeNode *> nodeDirList1;
        nodeDirList1.push_back(root);
        if(root != target1) {
            if(!findNodeDir(nodeDirList1, target1)) {
                nodeDirList1.pop_back();
            }
        }

        list<TreeNode *> nodeDirList2;
        nodeDirList2.push_back(root);
        if(root != target2) {
            if(!findNodeDir(nodeDirList2, target2)) {
                nodeDirList2.pop_back();
            }
        }

        auto it1 = nodeDirList1.begin();
        auto it2 = nodeDirList2.begin();

        TreeNode *ret = nullptr;

        for(; it1 != nodeDirList1.end() && it2 != nodeDirList2.end();
            it1++, it2++) {
            if(*it1 == *it2) {
                ret = *it1;
            } else {
                break;
            }
        }

        return ret;
    }
};
int main() { return 0; }
