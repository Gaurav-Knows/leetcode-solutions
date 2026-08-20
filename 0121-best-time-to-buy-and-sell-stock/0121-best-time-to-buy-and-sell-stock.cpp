class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=prices[0];
        int maxProfit=0;
        

        for(int i=1;i<prices.size();i++){
            if(minPrice>prices[i]){
                minPrice=prices[i];
            }
            else {
                int Profit=prices[i]-minPrice;
                maxProfit=max(maxProfit,Profit);


            }
            
            
        }
        return maxProfit;
        
    }
};