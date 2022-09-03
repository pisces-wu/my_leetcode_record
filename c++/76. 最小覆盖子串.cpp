#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution_76 {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char, int> sp, tp;
        for (auto& tt : t) {
            tp[tt]++;
        }
        int l = 0, r = 0;
        string ret;
        int rnt = 0;
        for (int i = 0, j = 0; i < s.size(); ++i) {
            sp[s[i]]++;
            if (sp[s[i]] <= tp[s[i]]) {
                rnt += 1;
            }
            while (sp[s[j]] > tp[s[j]]) {
                sp[s[j++]]--;
            }
            if (rnt == t.size()) {
                if (ret.empty() || i - j + 1 < s.size()) {
                    ret = s.substr(j, i - j + 1);
                }
            }
        }
        return ret;
    }
};
void main_76() {
    Solution_76 s_76;
    string s;
    string t;
    cin >> s;
    cin >> t;
    string ret=s_76.minWindow(s, t);
    cout << ret << endl;
}