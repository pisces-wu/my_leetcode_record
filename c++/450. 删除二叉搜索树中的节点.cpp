struct TreeNode
{
	int val;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
	TreeNode(int _val) :val(_val), left(nullptr), right(nullptr) {};
};
class Solution {
public:
    TreeNode* deleteOnenode(TreeNode* node) {
        if (node == nullptr) return node;
        if (node->right == nullptr) return node->left;
        TreeNode* cur = node->right;
        while (cur->left) {
            cur = cur->left;
        }
        cur->left = node->left;
        return node->right;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        TreeNode* pre = nullptr;
        TreeNode* cur = root;
        int val = key;
        while (cur && cur->val != val) {
            pre = cur;
            if (cur->val > val) {
                cur = cur->left;
            }
            else if (cur->val < val) {
                cur = cur->right;
            }
            else {
                break;
            }
        }
        if (pre == nullptr) {
            return deleteOnenode(cur);
        }
        if (pre->left && pre->left->val == key) {
            pre->left = deleteOnenode(cur);
        }
        if (pre->right && pre->right->val == key) {
            pre->right = deleteOnenode(cur);
        }
        return root;
    }
};