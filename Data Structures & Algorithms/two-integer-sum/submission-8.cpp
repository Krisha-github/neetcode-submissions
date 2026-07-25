class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; 
        for(int i = 0; i < nums.size(); i++){
            int y = target-nums[i];
            if(mp.contains(y)){
                return {mp[y], i}; 
            }
            mp[nums[i]] = i; 
        }
        return {};
    }
};
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n=nums.size();
//         vector<pair<int,int>> numsWithIndex;
//         for(int i=0;i<n;i++){
//             numsWithIndex.push_back({nums[i],i});
//         }
//         sort(numsWithIndex.begin(),numsWithIndex.end());
//         int left=0,right=n-1;
//         while(left<right){
//             int sum = numsWithIndex[left].first + numsWithIndex[right].first;
//             if(sum==target){
//                 if (numsWithIndex[left].second<= numsWithIndex[right].second)
//                 return {numsWithIndex[left].second, numsWithIndex[right].second};
//                 else 
//                 return { numsWithIndex[right].second,numsWithIndex[left].second};
//             }
//             else if(sum<target) left++;
//             else right--;
//         }
//         return {-1,-1};
//     }
// };
