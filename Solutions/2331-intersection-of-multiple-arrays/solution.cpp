class Solution {
public:
vector<int> intersection(vector< vector<int>>& v) {
unordered_map<int,int>cnt;
vector<int>inEach;
for(int i=0;i<v.size();i++) {
for(int j=0;j<v[i].size();j++) {
	cnt[ v[i][j] ]++;
	if(cnt[v[i][j]] == v.size()) inEach.push_back(v[i][j]); 
}
}

sort(inEach.begin(),inEach.end());
return inEach;
}

};
