class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>ans(n,1);
        vector<int>prepdt(n,1);
        vector<int>sufpdt(n,1);

        for(int i=1;i<n;i++){
            prepdt[i]=prepdt[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            sufpdt[i]=sufpdt[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++){
            ans[i]=prepdt[i]*sufpdt[i];
        }
        
        return ans;
    }
};
