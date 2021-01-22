class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int freq1[30]={0},freq2[30]={0};
        int sz1=word1.size(),sz2=word2.size();
        if(sz1!=sz2) return false;
        int id;
        for(int i=0;i<sz1;i++)
        {
            id=word1[i]-'a';
            freq1[id]++;
        }
        for(int i=0;i<sz2;i++)
        {
            id=word2[i]-'a';
            freq2[id]++;
        }
        
        vector<int>v1,v2;
        for(int i=0;i<26;i++)
        {
            if(freq1[i] and !freq2[i] ) return false;
            if(!freq1[i] and freq2[i] ) return false;
            if(freq1[i]) v1.push_back(freq1[i]);
            if(freq2[i]) v2.push_back(freq2[i]);
        }
        
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        
        if(v1.size()!=v2.size()) return false;
        for(int i=0;i<v1.size();i++)
            if(v1[i]!=v2[i]) return false;
        
        return true;
        
    }
};
