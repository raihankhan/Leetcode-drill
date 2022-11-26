// solution 1
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>freq;
        for(int i=0;i<tasks.size();i++) {
            freq[tasks[i]]++;
        }
        
        int ans=0;
        
        for(auto task : freq) {
            if(task.second == 1) {
                return -1;
            }
            if(task.second%3==0) {
                ans+= task.second/3;
            } else {
                ans+= task.second/3 + 1; 
            }
            
        } 
        return ans;
        
    }
};

// solution 2
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>freq;
        for(int i=0;i<tasks.size();i++) {
            freq[tasks[i]]++;
        }
        
        int ans=0;
        
        for(auto task : freq) {
            if(task.second == 1) {
                return -1;
            }
            ans+= (task.second+2)/3; 
        } 
        return ans;
        
    }
};