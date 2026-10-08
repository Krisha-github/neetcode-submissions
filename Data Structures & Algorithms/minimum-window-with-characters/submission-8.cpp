class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (m > n) return "";

        vector<int> mp(128, 0);
        for (char c : t) mp[c]++;

        int l = 0, in = 0;
        int mini = INT_MAX, leftpos = 0;

        for (int r = 0; r < n; r++) {
            if (mp[s[r]] > 0) in++;     // count only if still needed
            mp[s[r]]--;                  // may go negative = surplus

            while (in == m) {            // window valid -> shrink
                if (r - l + 1 < mini) {
                    mini = r - l + 1;
                    leftpos = l;
                }
                mp[s[l]]++;
                if (mp[s[l]] > 0) in--;  // lost a needed char
                l++;
            }
        }
        return mini == INT_MAX ? "" : s.substr(leftpos, mini);
    }
};