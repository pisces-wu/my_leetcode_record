#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;
class Solution_49 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        int n=strs.size();
        if(n==0){
            return ret;
        }
        unordered_map<string,vector<string>> map;
        for(int i=0;i<strs.size();++i){
            string ss=strs[i];
            sort(ss.begin(),ss.end());
            map[ss].push_back(strs[i]);
        }
        for(auto m:map){
            ret.push_back(m.second);
        }
        return ret;
    }
};
/*int main() {
    ///
}*/