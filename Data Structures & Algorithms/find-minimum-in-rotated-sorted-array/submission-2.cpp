class Solution {
public:
    int findMin(vector<int> &nums) {
        int mini=INT_MAX;
        int n=nums.size();
        int l=0;int r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            mini=min(nums[mid],mini);
            if(nums[mid]>=nums[r]){
                l=mid+1;
            }
            else if(nums[mid]<nums[l]){
                r=mid-1;
            }
            else{
                mini=min(mini,nums[l]);
                break;
            }
        }
        return mini;
    }
};
