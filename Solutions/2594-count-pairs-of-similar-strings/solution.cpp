class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<int,int>freq;
        for(int i=0;i<words.size();i++) {
            int hash = 0;
            for(int j=0;j<words[i].length();j++) {
                hash = hash | (1 << (words[i][j]-'a'));
            }
            freq[hash]++;
        }
        int ans = 0;
        for(auto n:freq) {
            if(n.second>=2) {
                ans += (n.second*(n.second-1))>>1;
            }
        }
        return ans;
    }
};
