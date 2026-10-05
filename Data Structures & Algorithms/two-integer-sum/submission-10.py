class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp={}
        for i in range(len(nums)):
            need=target-nums[i]
            if need in mp:
                return [mp[need],i]
            mp[nums[i]]=i              
        
        return []
#         vector<int> twoSum(vector<int>& nums, int target) {
#     unordered_map<int, int> mp;

#     for(int i = 0; i < nums.size(); i++) {
#         int need = target - nums[i];

#         if(mp.find(need) != mp.end()) {
#             return {mp[need], i};
#         }

#         mp[nums[i]] = i;
#     }

#     return {};
# }