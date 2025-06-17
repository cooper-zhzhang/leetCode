class Solution {
public:
    void flatten(TreeNode* root) { convertTree(root); }
    TreeNode* deepBuild(TreeNode* l, TreeNode* r) {
        TreeNode* ret = l;
        if (l == nullptr) {
            return r;
        }

        while (l->right != nullptr) {
            l = l->right;
        }
        l->right = r;
        return ret;
    }

    TreeNode* convertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* l = convertTree(root->left);
        TreeNode* r = convertTree(root->right);
        root->left = nullptr;
        root->right = deepBuild(l, r);

        return root;
    }
};
int main() { return 0; }
