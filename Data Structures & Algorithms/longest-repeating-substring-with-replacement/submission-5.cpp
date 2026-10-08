class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int longest=0;
        int l=0;
        int r=0;
        unordered_map<int,int> mp;
        int maxfreq=0;
            while(r<n){
                mp[s[r]]++;
                maxfreq=max(maxfreq,mp[s[r]]);
                while( (r-l+1) - maxfreq > k){
                    mp[s[l]]--;
                    if(mp[s[l]]==0){
                        mp.erase(s[l]);
                    }
                    //update maxfreq?? maxfreq--;
                    l++;
                }
                // A stale maxfreq can make the window stay at its current size when it should shrink, but it can never make it grow beyond a size that was already legitimately achieved. Since we only report the maximum size, the answer is still right
                int len=r-l+1;
                longest=max(len,longest);
                r++;
            }
        return longest;

    }
};
