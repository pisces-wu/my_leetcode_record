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
class Solution_106 {
public:
	int index = 0;
	unordered_map<int, int> map;
	int post_index;
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (postorder.size() < 1) return nullptr;
		for(auto& node:inorder){
			map[node] = index++;
		}
		post_index= postorder.size() - 1;
		return create_tree(0, postorder.size() - 1, inorder, postorder);
	}
	TreeNode* create_tree(int left, int right, vector<int>& inorder, vector<int>& postorder) {
		if (left > right) {
			return nullptr;
		}
		int node_val = postorder[post_index--];
		TreeNode* root = new TreeNode(node_val);
		int pose = map[node_val];
		root->right = create_tree(pose + 1, right, inorder, postorder);
		root->left = create_tree(left, pose - 1,inorder,postorder);
		return root;
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
void main_106() {
	Solution_106 s_106;
	vector<int> inorder;
	inorder.push_back(9);
	inorder.push_back(3);
	inorder.push_back(15);
	inorder.push_back(20);
	inorder.push_back(7);
	vector<int> postorder;
	postorder.push_back(9);
	postorder.push_back(15);
	postorder.push_back(7);
	postorder.push_back(20);
	postorder.push_back(3);
	TreeNode* root= s_106.buildTree(inorder, postorder);
	s_106.show_tree_inorder(root);
}