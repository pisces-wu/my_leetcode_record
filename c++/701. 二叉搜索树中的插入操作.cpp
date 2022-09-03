struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val) :val(_val),left(nullptr),right(nullptr) {};
};
class Solution_701 {
public:
    void recur(TreeNode* root, int val) {
        TreeNode* pre = new TreeNode(root->val);
        TreeNode* cur = root;
        while (cur) {
            if (cur->val > val) {
                pre = cur;
                cur = cur->left;
            }
            else if (cur->val < val) {
                pre = cur;
                cur = cur->right;
            }
        }
        if (pre->val > val) {
            pre->left = new TreeNode(val);
        }
        else {
            pre->right = new TreeNode(val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            root = new TreeNode(val);
            return root;
        }
        recur(root, val);
        return root;
    }
};