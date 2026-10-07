class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int best = 0;

        for (int num : st) {
            if (st.find(num - 1) == st.end()) {   // num starts a sequence
                int cur = num;
                int len = 1;
                while (st.find(cur + 1) != st.end()) {
                    cur++;
                    len++;
                }
                best = max(best, len);
            }
        }
        return best;
    }
};// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         map<int,int> mp;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             mp[nums[i]]=1;
//         }
//         for(auto it:mp){
//             if(mp.find(it.first -1) !=mp.end()){
//                 mp[it.first]=mp[it.first-1] + 1;
//             }
//         }
//         int longest=0;
//         for(auto &it: mp){
//             if(it.second>longest){
//                 longest=it.second;
//             }
            
//         }
//         return longest;
//     }
// };
