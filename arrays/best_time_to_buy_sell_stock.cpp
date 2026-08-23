//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Approach: track min price seen so far, update max profit at each step (single pass)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp=0, bb=prices[0];
        int n=prices.size();
        for(int i=1;i<n;i++){
            if(prices[i]>bb){
                mp=max(mp,prices[i]-bb);
            }
            bb=min(bb,prices[i]);
        }
        return mp;   
    }

};
