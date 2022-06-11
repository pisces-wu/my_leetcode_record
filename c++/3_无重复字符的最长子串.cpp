#include<iostream>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;
class solution_3 {
	public:
		int lengthOfLongestSubstring(string s) {
			int n = s.size();
			if (n <= 0) return 0;
			int max_l = 1;
			for (int i = 0; i < n; ++i) {
				unordered_set<int> st;
				st.insert(s[i]);
				for (int j = i + 1; j < n; ++j) {
					if (st.count(s[j])) {
						break;
					}
					else {
						st.insert(s[j]);
						if (st.size() > max_l) {
							max_l = st.size();
						}
					}
				}
			}
			return max_l;
		}
};
int main_3() {
	string s;
	cin >> s;
	solution_3 s3;
	cout<<s3.lengthOfLongestSubstring(s)<<endl;
	return 0;
}