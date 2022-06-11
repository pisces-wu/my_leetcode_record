#include<iostream>
#include<vector>
using namespace std;
struct listnode
{
	int val;
	listnode* next = nullptr;
	listnode() :val(0), next(nullptr) {};
	listnode(int a) :val(a), next(nullptr) {};
	listnode(int a, listnode* p) :val(a), next(p) {};
};
class solution_2 {
	public:
	listnode* add2num(listnode* l1, listnode* l2) {
		listnode* head = nullptr, *tail = nullptr;
		int carry = 0;
		while (l1 || l2) {
			int n1 = l1 ? l1->val : 0;
			int n2 = l2 ? l2->val : 0;
			int sum = n1 + n2 + carry;
			if (!head) {
				head = tail = new listnode(sum % 10);
			}
			else
			{
				tail->next = new listnode(sum % 10);
				tail = tail->next;
			}
			if (l1) {
				l1 = l1->next;
			}
			if (l2) {
				l2 = l2->next;
			}
			carry = sum/10;
		}
		if (carry > 0) {
			tail->next = new listnode(carry);
			tail = tail->next;
		}
		return head;
	}
};
int main_2() {
	int num;
	solution_2 s2;
	listnode* l1 = nullptr;
	listnode* l2 = nullptr;
	listnode* head1 = l1;
	listnode* head2 = l2;
	int flag1 = 0, flag2 = 0;
	while (cin >> num) {
		//l1->val = num;
		//l1 = l1->next;
		l1 = new listnode(num);
		if (flag1 == 0) {
			head1 = l1; flag1++;
		}
		cout << l1->val;
		l1=l1->next;
		if (cin.get() == '\n') break;
	}
	cout << '\n';
	while (head1 != nullptr) {
		cout << head1->val << " ";
		head1 = head1->next;
	}
	cin.clear();
	while (cin >> num) {
		//l2->val = num;
		l2 = new listnode(num);
		if (flag2 == 0) {
		    head2 = l2; flag2++;
		}
		l2 = l2->next;
		if (cin.get() == '\n') break;
	}
	listnode* head=s2.add2num(head1, head2);
	while (head!=nullptr) {
		cout << head->val << " ";
		head = head->next;
	}
	return 0;
}