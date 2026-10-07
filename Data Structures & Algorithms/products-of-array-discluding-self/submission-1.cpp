class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        long long pdt=1;
        bool onezero=0;;
        for(int i=0;i<n;i++){
            if(nums[i]==0 && onezero){
                pdt*=(long long)nums[i];
                return ans;
            }
            else if(nums[i]==0){
                onezero=1;
                continue;
            }
            else{
                pdt*=(long long)nums[i];
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=0)
            ans[i]=(int)(pdt/nums[i]);
            else {
                
                ans[i]=pdt;
                int j=i;
                for(int j=i-1;j>=0;j--){
                    ans[j]=0;
                }
                return ans;
            }
            
        }
        
        return ans;
    }
};
