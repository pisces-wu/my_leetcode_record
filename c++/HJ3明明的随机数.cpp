#include<iostream>
#include<set>
using namespace std;
void main_minming() {
	int n;
	cin >> n;
	set<int> dt;
	int num;
	while (n--) {
		cin >> num;
		dt.insert(num);
	}
	for (auto a : dt) {
		cout << a << " ";
	}
}