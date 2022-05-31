#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution_673 {
	public:
		int maxEnvelopes(vector<vector<int>>& envelopes) {
			int n = envelopes.size();
			if (n == 0) return 0;
			sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);});
			vector<int> dp = { envelopes[0][1] };
			for (int i = 0; i < n; ++i) {
				//if (envelopes[i][0] == envelopes[i - 1][0]||envelopes[i][1]==envelopes[i-1][1]) continue;
				if (envelopes[i][1] > dp.back()) {
					dp.push_back(envelopes[i][1]);
				}
				else {
					int p=lower_bound(dp.begin(),dp.end(),envelopes[i][1])-dp.begin();
					dp[p]=envelopes[i][1];
				}
			}
			return dp.size();

	}
};
int main() {
	vector<vector<int>> input;
	int a, b;
	while (cin >> a&&cin>>b) {
		input.push_back({ a,b });
		if (cin.get() == '\n') break;
	}
	solution_673 s_673;
	cout<<s_673.maxEnvelopes(input);

}