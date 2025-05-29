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
