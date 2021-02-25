class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        int buy[len+1];
        int profit[len+1];
        memset(profit, 0 , sizeof(profit));
        buy[0]=prices[0];
        profit[0]=0;
        for(int i=1;i<len;i++)
        {
            buy[i]=min(buy[i-1],prices[i]);
            profit[i]=max(profit[i-1],prices[i]-buy[i-1]);
        }
        
        return profit[len-1];
    }
};
