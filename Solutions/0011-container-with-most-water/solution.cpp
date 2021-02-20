class Solution {
public:
    int maxArea(vector<int>& h) {
        int water=0;
        int i=0,j=h.size()-1,min_h;
        
        while(i<j)
        {
            min_h=min(h[i],h[j]);
            water=max(water,min_h*(j-i));
            
            while(h[i]<=min_h and i<j) i++;
            while(h[j]<=min_h and i<j) j--;
        }
        
        return water;
        
    }
};
