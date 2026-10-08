class Solution {
public:
    int maxProfit(vector<int>& p) {
        int l=0;
        int n=p.size();
        int r=0;
        int maxprofit=0;
        while(r<n){
            while(p[l]>p[r]){
                l++;
            }
            int currprofit=p[r]-p[l];
            maxprofit=max(maxprofit,currprofit);
            r++;
        }
        return maxprofit;
    }
};
