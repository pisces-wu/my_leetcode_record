#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
	TreeNode(int _val) :val(_val), left(nullptr), right(nullptr) {};
};
class Solution_105 {
public:
    int pre_index = 0;
    int post_size;
    unordered_map<int, int> map;
    TreeNode* create_tree(int left, int right, vector<int>& preorder, vector<int>& inorder) {
        if (left > right) {
            return nullptr;
        }
        int _val = preorder[pre_index++];
        int pose = map[_val];
        TreeNode* root = new TreeNode(_val);
        root->left = create_tree(left, pose - 1, preorder, inorder);
        root->right = create_tree(pose + 1, right, preorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        post_size = preorder.size();
        if (post_size < 1) return nullptr;
        for (auto& s : inorder) {
            map[s] = pre_index++;
        }
        pre_index = 0;
        return create_tree(0, post_size - 1, preorder, inorder);
    }
	void show_tree_inorder(TreeNode* root) {
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty()) {
			TreeNode* cur = st.top();
			cout << cur->val << "  ";
			st.pop();
			if (cur->right) {
				st.push(cur->right);
			}
			if (cur->left) {
				st.push(cur->left);
			}
		}
	}
};