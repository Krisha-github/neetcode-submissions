class Solution {
public:
    int maxArea(vector<int>& h) {
        int maxarea=0;
        int n=h.size();
        int l=0;
        int r=n-1;
        
        while(l<r){
            int hi=min(h[l],h[r]);
            int w=r-l;
            int currarea=hi*w;
            maxarea=max(currarea,maxarea);
            
            if(h[l]<=h[r]) l++;
            else r--;
        }
        return maxarea;
    }
};
