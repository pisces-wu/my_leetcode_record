#include<iostream>
#include<vector>
using namespace std;
class Solution_1230 {
	public:
        //二维dp
        /*
        double probabilityOfHeads(vector<double>& prob, int target) {
            int n = prob.size();
            if (n == 0) return 0;
            vector<vector<double>> dp(n + 1, vector<double>(target + 1, 0));
            dp[0][0] = 1;
            for (int i = 1; i <= n; ++i) {
                for (int j = 0; j <= target && j <= i; ++j) {
                    if (j >= 1) {
                        dp[i][j] = dp[i - 1][j] * (1 - prob[i - 1]) + dp[i - 1][j - 1] * prob[i - 1];
                    }
                    else {
                        dp[i][j] = dp[i - 1][j] * (1 - prob[i - 1]);
                    }
                }
            }
            return dp[n][target];
        }
        */

        //一维滚动数组
        double probabilityOfHeads(vector<double>& prob, int target) {
            int n = prob.size();
            if (n == 0) return 0;
            vector<double> dp(n + 1);
            dp[0] = 1;
            for (int i = 1; i <= n; ++i) {
                for (int j = target; j >= 0; --j) {
                    if (j == 0) {
                        dp[j] = dp[j] * (1 - prob[i - 1]);
                    }
                    else {
                        dp[j] = dp[j] * (1 - prob[i - 1]) + dp[j - 1] * prob[i - 1];
                    }
                }
            }
            return dp[target];
        }
};
void main_1230() {
    double p;
    int target;
    vector<double> prob;
    while (cin >> p) {
        prob.push_back(p);
        if (cin.get() == '\n') {
            break;
        }
    }
    cin >> target;
    Solution_1230 s_1230;
    cout << s_1230.probabilityOfHeads(prob, target)<<endl;
}