#include<iostream>
#include<vector>
using namespace std;
class Solution_207 {
public:
	bool flag = true;
	vector<int> vst;
	vector<vector<int>> edge;
	void dfs(int i) {
		vst[i] = 1;
		for (auto& m : edge[i]) {
			if (vst[m] == 0 && flag) {
				dfs(m);
			}
			else if (vst[m] == 1) {
				flag = false;
				return;
			}
		}
		vst[i] = 2;
	}
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vst.resize(numCourses);
		edge.resize(numCourses);
		for (auto& m : prerequisites) {
			edge[m[1]].push_back(m[0]);
		}
		for (int i = 0; i < numCourses; ++i) {
			if (vst[i] == 0 && flag) {
				dfs(i);
			}
		}
		return flag;
	}

};
void main_207() {
	int numCourses = 0;
	cin >> numCourses;
	//vector<vector<int>> prerequisites(numCourses,vector<int>(2,0));
	vector<vector<int>> prerequisites;
	int num;
	int i = 0, j = 0;
	while (cin >> i>>j) {
		/*prerequisites[i][j++] = num;
		if (j == 2) ++i;
		j = j % 2;
		*/
		prerequisites.push_back({ i,j });
		if (cin.get() == '\n') break;
	}
	//for (auto m : prerequisites) {
	//	cout << m[0] <<"  "<< m[1]<<endl;
	//}
	Solution_207 s_207;
	if (s_207.canFinish(numCourses, prerequisites)) {
		cout << "True";
		return;
	}
	cout << "False";
}