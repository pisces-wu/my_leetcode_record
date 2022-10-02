#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode(int _val) :val(_val), left(nullptr), right(nullptr) {}
    //TreeNode(int _val,TreeNode* _left=nullptr,TreeNode* _right=nullptr) :val(_val), left(_left), right(_right){}

};
struct ListNode {
    int val;
    ListNode* next = nullptr;
    ListNode(int _val) :val(_val) {};
    //ListNode(int _val, ListNode* _next = nullptr) :val(_val), next(_next) {};
};
class Solution_109 {
public:
    TreeNode* recur(vector<int>& res, int l, int r) {
        if (l > r) return nullptr;
        int mid = (l + r) / 2;
        TreeNode* node = new TreeNode(res[mid]);
        node->left = recur(res, l, mid - 1);
        node->right = recur(res, mid + 1, r);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        vector<int> res;
        ListNode* node = head;
        while (node) {
            res.push_back(node->val);
            node = node->next;
        }
        int l = 0, r = res.size() - 1;
        return recur(res, 0, r);
    }
};
void show(TreeNode* node) {
    if (node == nullptr) { cout << "NULL"<<" "; return; }
    cout << node->val<<" ";
    show(node->left);
    show(node->right);
}
int main_109() {
    int num;
    ListNode* list = new ListNode(0);
    ListNode* head = list;
    while (cin >> num) {
       list->next = new ListNode(num);
       list = list->next;
       if (cin.get() == '\n') break;
    }
    Solution_109 s_109;
    TreeNode* ret=s_109.sortedListToBST(head->next);
    show(ret);
    return 0;
}